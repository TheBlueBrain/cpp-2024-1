//
// Created by arnas on 4/28/24.
//

#ifndef CPP_2024_1_PERSONPRINTFULLNAME_H
#define CPP_2024_1_PERSONPRINTFULLNAME_H



#include "Personprint.h"

class PersonPrintFullName : public Personprint{
public:
    void print(const Person &p) override;
    ~PersonPrintFullName();
};


#endif //CPP_2024_1_PERSONPRINTFULLNAME_H
