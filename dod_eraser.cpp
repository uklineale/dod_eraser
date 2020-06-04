#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

void erase(char *data, int len) {
    memset(data, 0, len);
    memset(data, 1, len);

    for (int i = 0; i < len; i++){
        char random_byte = rand() % 256;
        data[i] = random_byte;
    }
}

int main() {
    string data = "Oh my gosh this is top secret and needs to be deleted\n";
    int len = data.size();

    srand(time(NULL));

    cout << data;

    erase((char *) data.c_str(), len);

    cout << data << "\n";

}