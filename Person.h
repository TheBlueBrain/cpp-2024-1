//
// Created by arnas on 2/12/24.
//

#ifndef CPP_2024_1_PERSON_H
#define CPP_2024_1_PERSON_H


#include <string>
#include <memory>



#include "Trackable.h"
#include "Personprint.h"
class Personprint;
#include "PersonPrintFullName.h"
class PersonPrintFullName;

class Person: public Trackable {
private:
    class Impl;
    Impl *pimpl;
    TrackableProtected *parentp;
public:
    Personprint *prt = nullptr;
    static unsigned long NID;
    Person(std::string name, std::string lastName);
    Person();
    std::string getName() const;
    void print() const override;
    ~Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    Person& operator=(Person&& other);
    static void changeName(std::string NewName, Trackable *obj);
    friend std::ostream & operator << (std::ostream &o, const Person &p);
    friend std::istream & operator >> (std::istream &i, Person &p);
};


#endif //CPP_2024_1_PERSON_H
