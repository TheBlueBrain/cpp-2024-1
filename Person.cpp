//
// Created by arnas on 2/12/24.
//

#include <iostream>
#include <ctime>
#include "Person.h"

struct Person::Impl{
    std::string firstName, lastName;
Impl(std::string Fname, std::string Lname){
    firstName=Fname;
    lastName=Lname;
}
};
Person::Person(std::string name, std::string lastName) :pimpl(new Impl(name, lastName)) {

    Name = name + " " + lastName;
    pimpl->firstName = name;
    pimpl->lastName = lastName;
}

void Person::print() const{
    std::cout<<"ENTRY ID: "<< ID <<" Given name: "<<pimpl->firstName<<" Last name: "<<pimpl->lastName<<" Date of entry: "<< std::ctime(&Time);
}

Person::~Person() {
    amount--;
}

void Person::changeName(std::string NewName, Trackable* obj) {
    Person *cast = dynamic_cast<Person*>(obj);
    if(cast){
        cast ->pimpl->firstName = NewName;
    }else{
        throw std::bad_cast();
    }


}

std::string Person::getName() const{
    return Name;
}

Person::Person(const Person& other) {
    Name = other.Name;
    pimpl->firstName = other.pimpl->firstName;
    pimpl->lastName = other.pimpl->lastName;
}

Person &Person::operator=(const Person &other) {
    return *this = Person(other);
}

Person &Person::operator=(Person &&other){
    if(this == &other){
        return *this;
    }
    Name = other.Name;
    pimpl->firstName = other.pimpl->firstName;
    pimpl->lastName = other.pimpl->lastName;
    ID = other.ID;
    other.pimpl->firstName = "";
    other.pimpl->lastName = "";
    other.Name = "";
    other.ID = 0;
    return *this;
}
