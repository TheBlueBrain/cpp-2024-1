//
// Created by arnas on 2/12/24.
//

#ifndef CPP_2024_1_PERSON_H
#define CPP_2024_1_PERSON_H


#include <string>
#include "Trackable.h"

class Person:public Trackable {
private:
    std::string firstName, lastName;
public:
    Person(std::string name, std::string lastName);
    void print() override;
    ~Person();
    void changeName(std::string NewName);
};


#endif //CPP_2024_1_PERSON_H
