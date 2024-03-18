//
// Created by arnas on 2/25/24.
//

#include "Trackable.h"
#include <string>
#include <ctime>
#include <iostream>
unsigned long Trackable::amount = 0;
unsigned long Trackable::NID = 0;
Trackable::Trackable(std::string Name) : Time(time(0)){
    this->Name = Name;
    this->ID = NID;
    NID++;
    amount++;
}

 void Trackable::print() const {
    std::cout << "ENTRY ID " << ID << " Name of object: " << Name << " Time of entry: " << std::ctime(&Time);
}

Trackable::~Trackable() {
    amount--;
}

Trackable::Trackable() : Time(time(0)){
    this->ID = Trackable::NID;
    NID++;
    amount++;
}

std::string Trackable::getName() const {
    return Name;
}

Trackable::Trackable(const Trackable &other) :Time(other.Time){
    Name = other.Name;
    ID = other.ID;
}

Trackable &Trackable::operator=(const Trackable &other) {
    return *this = Trackable(other);
}

Trackable &Trackable::operator=(Trackable &&other) noexcept {
    if(this == &other){
        return *this;
    }
    Name = other.Name;
    ID=other.ID;
    other.Name = "";
    other.ID = 0;
    return *this;
}

