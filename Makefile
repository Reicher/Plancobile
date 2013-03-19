# Makefile for Plancobile
CC=g++
CFLAGS=-I/usr/local/include -I/include -I/src -c 
LFLAGS=-L/usr/local/lib -lwiringPi -o

CFLAGSLIGHT= -I/src -c
LFLAGSLIGHT= -o

all: Plancobile ClientApp

ClientApp: client.o clientMain.o
	$(CC) $(LFLAGSLIGHT) ClientApp.o client.o clientMain.o
clientMain.o: src/clientMain.cpp
	$(CC) $(CFLAGSLIGHT) src/clientMain.cpp
Plancobile: main.o DCMotor.o server.o client.o
	$(CC) $(LFLAGS) Plancobile.o main.o DCMotor.o server.o client.o 
main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp
DCMotor.o: src/DCMotor.cpp include/DCMotor.h
	$(CC) $(CFLAGS) src/DCMotor.cpp
server.o: src/server.cpp include/server.h
	$(CC) $(CFLAGS) src/server.cpp
client.o: src/client.cpp include/client.h
	$(CC) $(CFLAGSLIGHT) src/client.cpp
clean: 
	rm -rf *.o
