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
    for(auto Entrie : Entries){
        Entrie->print();
    }
    Person *cast = dynamic_cast<Person*>(Entries[6]);
    if(cast){
        cast->changeName("Vardenis");
    }else{
        std::cout<<"Not a person"<<std::endl;
    }
    for(auto Entrie : Entries){
        Entrie->print();
    }
    return 0;
}
