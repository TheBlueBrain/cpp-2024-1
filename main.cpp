#include <iostream>
#include "Trackable.h"
#include "Person.h"

int main() {
    Trackable* test = new Trackable("Arnas Sniokaitis");
    test->print();
    return 0;
}
