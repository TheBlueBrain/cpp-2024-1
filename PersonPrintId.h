//
// Created by arnas on 4/28/24.
//

#ifndef CPP_2024_1_PERSONPRINTID_H
#define CPP_2024_1_PERSONPRINTID_H


#include "Personprint.h"

class PersonPrintId : public Personprint{
public:
    void print(const Person &p) override;

};


#endif //CPP_2024_1_PERSONPRINTID_H
