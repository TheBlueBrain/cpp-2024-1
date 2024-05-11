default: cpp1
cpp1: main.o Person.o Trackable.o Personprint.o PersonPrintFullName.o PersonPrintId.o TrackableProtected.o
	g++ main.o Person.o Trackable.o Personprint.o PersonPrintFullName.o PersonPrintId.o TrackableProtected.o -o cpp1.out
main.o: main.cpp
	g++ -c main.cpp -o main.o
Person.o: Person.cpp Person.h
	g++ -c Person.cpp -o Person.o
Trackable.o: Trackable.cpp
	g++ -c Trackable.cpp -o Trackable.o
Personprint.o: Personprint.cpp
	g++ -c Personprint.cpp -o Personprint.o
PersonPrintFullName.o: PersonPrintFullName.cpp
	g++ -c PersonPrintFullName.cpp -o PersonPrintFullName.o
PersonPrintId.o: PersonPrintId.cpp
	g++ -c PersonPrintId.cpp -o PersonPrintId.o
TrackableProtected.o: TrackableProtected.cpp
	g++ -c TrackableProtected.cpp -o TrackableProtected.o
clean:
	rm -f cpp1 main.o Person.o Trackable.o Personprint.o PersonPrintFullName.o PersonPrintId.o TrackableProtected.o
buildAll: cpp1
rebuild: clean buildAll
