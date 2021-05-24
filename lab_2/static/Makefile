binary: main.o libclient.a
	g++ -o binary main.o -L. -lclient

main.o: main.cpp
	g++ -c main.cpp

libclient.a: Client.o
	ar cr libclient.a Client.o

Client.o: Client.cpp
	g++ -c Client.cpp

clean:
	rm -f *.o *.a binary
