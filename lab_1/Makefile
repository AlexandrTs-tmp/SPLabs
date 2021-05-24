CC=g++
CFLAGS=-c -Wall

all: main

main: main.o Client.o
	$(CC) main.o Client.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

client.o: Client.cpp
	$(CC) $(CFLAGS) Client.cpp

clean: 
	rm -rf *.o main
