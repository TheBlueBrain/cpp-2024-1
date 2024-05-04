//
// Created by arnas on 2/25/24.
//

#include "Trackable.h"
#include <string>
#include <ctime>
#include <iostream>
unsigned long Trackable::amount = 0;
/**
 * Paprastas konstruktorius
 * @param Name
 */
Trackable::Trackable(std::string Name) : proc(new TrackableProtected(Name)){
    this->ID = TrackableProtected::NID;
    TrackableProtected::NID++;
    amount++;
}


/**
 * Destruktorius
 */
Trackable::~Trackable() {
    amount--;
}
/**
 * Tuscias konstruktorius
 */
Trackable::Trackable() : proc(new TrackableProtected()){
    ID = proc->NID;
    TrackableProtected::NID++;
    amount++;
}
/**
 * de facto to string
 * @return
 */
std::string Trackable::getName() const {
    return proc->Name;
}
/**
 * Copy construktorius
 * @param other Trackable, is kurio kopijuojama
 */
Trackable::Trackable(const Trackable &other) :proc(new TrackableProtected(other.getProtected())){
    ID = other.ID;
}
/**
 * Copy assignment
 * @param other Trackable, is kurio kopijuojama
 * @return nukopijuotas trackable
 */
Trackable &Trackable::operator=(const Trackable &other) {
    return *this = Trackable(other);
}
/**
 * Move assignment
 * @param other Trackable is kurio imti
 * @return Moveintas Trackable
 */
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
/**
 *
 * @return rodykle i protected klase
 */
const TrackableProtected *Trackable::getProtected() const {
    return proc;
}
/**
 * vardo rasymas
 */
void Trackable::print() const {
    std::cout << proc->Name << "\n";
}

