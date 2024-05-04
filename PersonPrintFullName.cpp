//
// Created by arnas on 4/28/24.
//

#include <iostream>
#include "PersonPrintFullName.h"
#include "Person.h"
/**
 * Atspauzdinti varda i console
 * @param p Zmogus is kurio iskviesta funkcija
 */
void PersonPrintFullName::print(const Person &p) {

    std::cout<<p.getName()<<"\n";

}
