# Makefile for Plancobile
CC=g++
CFLAGS=-I/usr/local/include -I/include -I/src -c 
LFLAGS=-L/usr/local/lib -lwiringPi -o

all: main.o DCMotor.o Server.o
	$(CC) $(LFLAGS) Plancobile main.o DCMotor.o Server.o 
main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp
DCMotor.o: src/DCMotor.cpp include/DCMotor.h
	$(CC) $(CFLAGS) src/DCMotor.cpp
Server.o: src/Server.cpp include/Server.h
	$(CC) $(CFLAGS) src/Server.cpp
clean: 
	rm -rf *.o Plancobile
