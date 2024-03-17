#include <iostream>
#include "Trackable.h"
#include "Person.h"

void printAmount(){
    std::cout<<Trackable::amount<<std::endl;
}

int main() {

    Trackable* test1 = new Trackable("Netipizuotas irasas");
    test1->print();
    printAmount();
    Trackable* test2 = new Person("vardas", "pavarde");
    printAmount();
    test2->print();
    Trackable *Entries[7];
    for(int i = 0; i < 3; ++i){
        std::string name;
        std::cin >> name;
        Entries[i] = new Trackable(name);
    }
    for(int i = 0; i < 4; ++i){
        std::string f, l;
        std::cin >> f >> l;
        Entries[3 + i] = new Person(f, l);
    }
    for(auto Entry : Entries){
        Entry->print();
    }
    Person::changeName("Vardenis", Entries[6]);
    for(auto Entry : Entries){
        Entry->print();
    }
    printAmount();
    delete Entries[6];
    printAmount();
    return 0;
}
