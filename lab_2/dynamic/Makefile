binary: UserInterface.o libtest.so
	g++ -o binary UserInterface.o -L. -ltest -Wl,--rpath,.

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

libtest.so: Employee.o Database.o
	g++ -shared -o libtest.so Employee.o Database.o

Employee.o: Employee.cpp
	g++ -c -fPIC Employee.cpp

Database.o: Database.cpp
	g++ -c -fPIC Database.cpp

clean:
	rm -f *.o *.so binary
