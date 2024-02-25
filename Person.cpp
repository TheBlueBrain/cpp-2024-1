//
// Created by arnas on 2/12/24.
//

#include <iostream>
#include <ctime>
#include "Person.h"


Person::Person(std::string name, std::string lastName) {
    Name = name + " " + lastName;
    firstName = name;
    this->lastName = lastName;
}

void Person::print() {
    std::cout<<"ENTRY ID: "<< ID <<" Given name: "<<firstName<<" Last name: "<<lastName<<" Date of entry: "<< std::ctime(&Time);
}

Person::~Person() {
    amount--;
}
