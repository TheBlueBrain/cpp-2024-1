//
// Created by arnas on 4/28/24.
//

#include <iostream>
#include "PersonPrintFullName.h"
#include "Person.h"
void PersonPrintFullName::print(const Person &p) {

    std::cout<<p.getName()<<"\n";

}
