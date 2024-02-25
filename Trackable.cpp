//
// Created by arnas on 2/25/24.
//

#include "Trackable.h"
#include <string>
#include <ctime>
#include <iostream>
unsigned long Trackable::amount = 0;
unsigned long Trackable::NID = 0;
Trackable::Trackable(std::string Name){
    this->Name = Name;
    this->ID = NID;
    NID++;
    amount++;
    Time = time(0);
}

void Trackable::print() {
    std::cout << "ENTRY ID " << ID << " Name of object: " << Name << " Time of entry: " << std::ctime(&Time) << std::endl;
}

Trackable::~Trackable() {
    amount--;
}

Trackable::Trackable() {
    this->ID = NID;
    NID++;
    amount++;
    Time = time(0);
}
