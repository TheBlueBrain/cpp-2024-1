#include <iostream>
#include <fstream>
#include "Trackable.h"
#include "Person.h"
#include "PersonPrintId.h"

void printAmount(){
    std::cout<<Trackable::amount<<std::endl;
}

int main() {
    Trackable* test1 = new Trackable("Netipizuotas irasas");
    std::ofstream out("TEST.abc");
    test1->print();
    printAmount();
    Trackable* test2 = new Person("vardas", "pavarde");
    test2->print();
    printAmount();
    //Trackable *Entries[7];
    Trackable ** Ent;
    Ent = new Trackable*[7];
    for(int i = 0; i < 3; ++i){
        std::string name;
        std::cin >> name;
        Ent[i] = new Trackable(name);
        //Entries[i] = new Trackable(name);
    }
    for(int i = 0; i < 4; ++i){
        std::string f, l;
        std::cin >> f >> l;
        Ent[3 + i] = new Person(f, l);
        //Entries[3 + i] = new Person(f, l);
    }
    /*for(auto Entry : Entries){
        Entry->print();
    }*/
    for(int i = 0; i < 7; ++i){
        Ent[i]->print();
    }
    try {
    //    Person::changeName("Vardenis", Entries[6]);
        Person::changeName("Vardenis", Ent[6]);

    }catch(std::bad_cast) {
        std::cout<<"Klaida keiciant 6\n";
    }
    try {
   //     Person::changeName("Vardenis", Entries[0]);
        Person::changeName("Vardenis", Ent[0]);
    }catch(std::bad_cast) {
        std::cout<<"Klaida keiciant 0\n";
    }
    Person *cast = dynamic_cast<Person*>(Ent[6]);
    out<<*cast;
    out.close();
   /* for(auto Entry : Entries){
        Entry->print();
    }*/
    for(int i = 0; i < 7; i++){
        Ent[i]->print();
    }
    printAmount();
    //delete Entries[6];
    delete Ent[6];
    printAmount();
    Person *p = new Person("A", "B");
    p->print();
    p->prt=new PersonPrintId();
    p->print();

    std::ifstream in("TEST.abc");
    Person per;

    in>>per;

    per.print();
    return 0;
}
