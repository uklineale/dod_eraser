#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

streamsize file_size(string filename) {

    ifstream f;
    f.open(filename.c_str(), ios::in|ios::binary);

    f.ignore(numeric_limits<streamsize>::max());
    streamsize length = f.gcount();
    f.close();

    return length;
}

void erase(string filename) {

    streamsize size = file_size(filename);
    cout << "Writing " << size << " number of bytes\n";

    ofstream f;
    f.open(filename.c_str(), ios::out|ios::binary);
    f.seekp(0, ios::beg);


    char *to_write = new char[size];
    fill_n(to_write, size, 0);
    f.write(to_write, size);
    f.seekp(0, ios::beg);

    fill_n(to_write, size, 1);
    f.write(to_write, size);
    f.seekp(0, ios::beg);

    for (int i = 0; i < size; i++){
        char random_byte = rand() % 256;
        to_write[i] = random_byte;
    }
    f.write(to_write, size);
    
    f.close();
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Requires a single arg, the filename to delete.\n";
        exit(1);
    }
    string filename = argv[1];
    // Seed RNG with current timestamp
    srand(time(NULL));
    erase(filename);

}