CC = g++
CFLAGS = -g -Wall -std=c++0x

dod_eraser: dod_eraser.o
	$(CC) -o dod_eraser dod_eraser.cpp