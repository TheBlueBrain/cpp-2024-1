//
// Created by arnas on 4/28/24.
//

#include <iostream>
#include "PersonPrintId.h"

#include "Person.h"
/**
 * Atspauzdinti ID i konsole
 * @param p Zmogus is kurio iskviesta funkcija
 */
void PersonPrintId::print(const Person &p) {

    std::cout << p.ID << "\n";

}
