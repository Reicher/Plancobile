# Makefile for Plancobile
CC=g++
CFLAGS=-I/usr/local/include -c 
LFLAGS=-L/usr/local/lib -lwiringPi -o

all: main.o
	$(CC) $(LFLAGS) Plancobile main.o 
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
clean: 
	rm -rf *.o Placobile
