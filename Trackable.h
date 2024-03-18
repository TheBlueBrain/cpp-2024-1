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
    virtual std::string getName() const;
    unsigned type;
    static unsigned long amount;
    unsigned long ID;
    Trackable(std::string Name);
    Trackable();
    virtual void print() const;
    Trackable(const Trackable& other);
    Trackable& operator=(const Trackable& other);
    Trackable& operator=(Trackable&& other) noexcept;
    ~Trackable();

};


#endif //CPP_2024_1_TRACKABLE_H
