//
// Created by arnas on 2/12/24.
//

#include <iostream>
#include <ctime>
#include <sstream>
#include "Person.h"
#include "PersonPrintFullName.h"
#include "PersonPrintId.h"

struct Person::Impl{
    std::string firstName, lastName;
    Impl(std::string Fname, std::string Lname){
        firstName=Fname;
        lastName=Lname;
    }
    Impl(){};
    Impl(const Person& oth){
        firstName = oth.pimpl->firstName;
        lastName = oth.pimpl->lastName;
    }
};
Person::Person(std::string name, std::string lastName) : pimpl(new Impl(name, lastName)) {
    parentp = getProtected();
    parentp ->Name = name + " " + lastName;
    prt = new PersonPrintFullName();
}

void Person::print() const{
    prt->print(*this);
    //std::cout<<"ENTRY ID: "<< ID <<" Given name: "<<pimpl->firstName<<" Last name: "<<pimpl->lastName<<" Date of entry: "<< std::ctime(&parentp->Time);
}

Person::~Person() {
    delete  parentp;
    delete pimpl;
}

void Person::changeName(std::string NewName, Trackable* obj) {
    Person *cast = dynamic_cast<Person*>(obj);
    if(cast){
        cast ->pimpl->firstName = NewName;
        cast ->parentp->Name = NewName + cast->pimpl->lastName;
    }else{
        throw std::bad_cast();
    }
}

std::string Person::getName() const{
    return this->pimpl->firstName + " "+ this->pimpl->lastName;
}
Person::Person(const Person& other) :pimpl(new Impl(other)) {
    parentp = getProtected();
    parentp->Name = other.parentp->Name;
    prt = new PersonPrintFullName();
}

Person &Person::operator=(const Person &other) {
    return *this = Person(other);
}

Person &Person::operator=(Person &&other){
    if(this == &other){
        return *this;
    }
    parentp->Name = other.parentp->Name;
    pimpl->firstName = other.pimpl->firstName;
    pimpl->lastName = other.pimpl->lastName;
    ID = other.ID;
    other.pimpl->firstName = "";
    other.pimpl->lastName = "";
    other.parentp->Name = "";
    other.ID = 0;
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Person &p) {
    o<<p.pimpl->firstName;
    o<<" "<<p.pimpl->lastName<<" ";
    std::ostringstream ss;
    ss<<p.parentp->Time;
    o<<ss.str()<<" ";
    o<<p.ID<<" ";
    o<<p.type<<" ";
    Personprint* pri = dynamic_cast<PersonPrintFullName*>(p.prt);
    if(pri){
        o<<"N\n";
    }else{
        o<<"I\n";
    }
    return o;
}

std::istream &operator>>(std::istream &i, Person &p) {
    i>>p.pimpl->firstName;
    i>>p.pimpl->lastName;
    std::string raw, type;
    i>>raw;
    std::istringstream is(raw);
    is>>p.parentp->Time;
    i>>p.ID;
    i>>p.type;
    i>>type;
    if(type == "N"){
        p.prt = new PersonPrintFullName;
    }else{
        p.prt = new PersonPrintId;
    }
    return i;
}

Person::Person() : pimpl(new Impl("", "")) {
    parentp = getProtected();
    prt = new PersonPrintFullName();
}
