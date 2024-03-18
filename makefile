default: cpp1
cpp1: main.o Person.o Trackable.o 
	g++ main.o Person.o Trackable.o -o cpp1
main.o: main.cpp
	g++ -c main.cpp -o main.o
Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o
Trackable.o: Trackable.cpp
	g++ -c Trackable.cpp -o Trackable.o
clean:
	rm -f cpp1 main.o Person.o Trackable.o
buildAll: cpp1
rebuild: clean buildAll
