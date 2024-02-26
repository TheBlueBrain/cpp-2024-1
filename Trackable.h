//
// Created by arnas on 2/25/24.
//

#ifndef CPP_2024_1_TRACKABLE_H
#define CPP_2024_1_TRACKABLE_H
#include <string>

class Trackable {
protected:
    static unsigned long NID;
    std::string Name;
    const time_t Time;
public:
    virtual const std::string getName();
    unsigned type;
    static unsigned long amount;
    unsigned long ID;
    Trackable(std::string Name);
    Trackable();
    virtual const void print();
    ~Trackable();

};


#endif //CPP_2024_1_TRACKABLE_H
