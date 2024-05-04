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
    /**
     * Paprastas konstruktorius
     * @param Fname vardas
     * @param Lname Pavarde
     */
    Impl(std::string Fname, std::string Lname){
        firstName=Fname;
        lastName=Lname;
    }
    /**
     * Tuščias konstruktorius
     */
    Impl(){};
    /**
     * Konstruktoriaus kopijavimas
     * @param oth Person is kurio kopijuojama
     */
    Impl(const Person& oth){
        firstName = oth.pimpl->firstName;
        lastName = oth.pimpl->lastName;
    }
};
/**
 * Konstruktorius
 * @param name Žmogaus vardas
 * @param lastName Žmogaus pavardė.
 */
Person::Person(std::string name, std::string lastName) : pimpl(new Impl(name, lastName)) {
    parentp = getProtected();
    parentp ->Name = name + " " + lastName;
    prt = new PersonPrintFullName();
}
/**
 * de facto "to String"
 */
void Person::print() const{
    prt->print(*this);
    //std::cout<<"ENTRY ID: "<< ID <<" Given name: "<<pimpl->firstName<<" Last name: "<<pimpl->lastName<<" Date of entry: "<< std::ctime(&parentp->Time);
}
/**
 * destruktorius.
 */
Person::~Person() {
    delete  parentp;
    delete pimpl;
}
/**
 * Pakeičia vardą į naują.
 * @param NewName naujas vardas.
 * @param obj Sekamas objektas, kurio vardas bus pakeistas.
 */
void Person::changeName(std::string NewName, Trackable* obj) {
    Person *cast = dynamic_cast<Person*>(obj);
    if(cast){
        cast ->pimpl->firstName = NewName;
        cast ->parentp->Name = NewName + cast->pimpl->lastName;
    }else{
        throw std::bad_cast();
    }
}
/**
 * Gauti vardą.
 * @return Vardas
 */
std::string Person::getName() const{
    return this->pimpl->firstName + " "+ this->pimpl->lastName;
}
/**
 * Copy konstruktorius
 * @param other iš ko kopijuojamaa.
 */
Person::Person(const Person& other) :pimpl(new Impl(other)) {
    parentp = getProtected();
    parentp->Name = other.parentp->Name;
    prt = other.prt;
}
/**
 * Copy assignment
 * @param other Žmogus, iš kurio imami duomenys.
 * @return
 */
Person &Person::operator=(const Person &other) {
    return *this = Person(other);
}
/**
 * Move assignment
 * @param other
 * @return Žmogus, iš kurio imami duomenys.
 */
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
/**
 * Išvedimo srauto perrašymas.
 * @param o output stautas
 * @param p Žmogus p, kuris paduodamas  srautą.
 * @return srautas o
 */
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
/**
 * Ivesties binarinio srauto perrašymas, kada būtų galima objektą perduoti į jį.
 * @param i input sraautas
 * @param p Žmogus p, kurio duomenys imami iš srauto.
 * @return input srautas
 */
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
/**
 * Tuščias konstruktorius.
 */
Person::Person() : pimpl(new Impl("", "")) {
    parentp = getProtected();
    prt = new PersonPrintFullName();
}
