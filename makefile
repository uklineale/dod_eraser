CC = g++
CFLAGS = -std=c++11

dod_eraser: dod_eraser.o
	$(CC) -o dod_eraser dod_eraser.cpp