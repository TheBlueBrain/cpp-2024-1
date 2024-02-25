//
// Created by arnas on 2/25/24.
//

#ifndef CPP_2024_1_TRACKABLE_H
#define CPP_2024_1_TRACKABLE_H
#include <string>

class Trackable {
    static unsigned long NID;
public:
    std::string Name;
    time_t Time;
    static unsigned long amount;
    unsigned long ID;
    Trackable(std::string Name);

    Trackable();

    void print();
    ~Trackable();

};


#endif //CPP_2024_1_TRACKABLE_H
