//
// Created by arnas on 2/25/24.
//

#include "Trackable.h"
#include <string>
#include <ctime>
#include <iostream>
unsigned long Trackable::amount = 0;

Trackable::Trackable(std::string Name) : proc(new TrackableProtected(Name)){
    this->ID = TrackableProtected::NID;
    TrackableProtected::NID++;
    amount++;
}

 void Trackable::print() const {
    std::cout << "ENTRY ID " << ID << " Name of object: " << proc->Name << " Time of entry: " << std::ctime(&proc->Time);
}

Trackable::~Trackable() {
    amount--;
}

Trackable::Trackable() : proc(new TrackableProtected()){
    ID = proc->NID;
    TrackableProtected::NID++;
    amount++;
}

std::string Trackable::getName() const {
    return proc->Name;
}

Trackable::Trackable(const Trackable &other) :proc(new TrackableProtected(other.getProtected())){
    ID = other.ID;
}

Trackable &Trackable::operator=(const Trackable &other) {
    return *this = Trackable(other);
}

Trackable &Trackable::operator=(Trackable &&other) noexcept {
    if(this == &other){
        return *this;
    }
    proc->Name = other.proc->Name;
    ID=other.ID;
    other.proc->Name = "";
    other.ID = 0;
    return *this;
}

const TrackableProtected *Trackable::getProtected() const {
    return proc;
}

TrackableProtected *Trackable::getProtected() {
    return proc;
}

