//
// Created by arnas on 2/25/24.
//

#include "Trackable.h"
#include <string>
#include <ctime>
#include <iostream>
unsigned long Trackable::amount = 0;
struct Trackable::ImplTrack{
    ImplTrack(const Trackable trackable) :Time(trackable.p->Time){
        Name = trackable.p->Name;
    }

    static unsigned long NID;
    std::string Name;
    const time_t Time;
    ImplTrack(std::string name):Time(time(0)){
        Name=name;
    }
    ImplTrack():Time(time(0)){
    }

};
Trackable::Trackable(std::string Name) : p(new ImplTrack(Name)){
    this->ID = p->NID;
    p->NID++;
    amount++;
}

 void Trackable::print() const {
    std::cout << "ENTRY ID " << ID << " Name of object: " << p->Name << " Time of entry: " << std::ctime(&p->Time);
}

Trackable::~Trackable() {
    amount--;
}

Trackable::Trackable() : p(new ImplTrack()){
    this->ID = p->NID;
    p->NID++;
    amount++;
}

std::string Trackable::getName() const {
    return p->Name;
}

Trackable::Trackable(const Trackable &other) :p(new ImplTrack(other)){
    ID = other.ID;
}

Trackable &Trackable::operator=(const Trackable &other) {
    return *this = Trackable(other);
}

Trackable &Trackable::operator=(Trackable &&other) noexcept {
    if(this == &other){
        return *this;
    }
    p->Name = other.p->Name;
    ID=other.ID;
    other.p->Name = "";
    other.ID = 0;
    return *this;
}

