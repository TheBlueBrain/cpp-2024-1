//
// Created by arnas on 2/12/24.
//

#ifndef CPP_2024_1_PERSON_H
#define CPP_2024_1_PERSON_H


#include <string>
#include <memory>
#include "Trackable.h"

class Person:public Trackable {
private:
    class Impl;
    Impl *pimpl;
public:
    static unsigned long NID;
    Person(std::string name, std::string lastName);
    std::string getName() const;
    void print() const override;
    ~Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    Person& operator=(Person&& other);
    static void changeName(std::string NewName, Trackable *obj);
};


#endif //CPP_2024_1_PERSON_H
