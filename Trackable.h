//
// Created by arnas on 2/25/24.
//

#ifndef CPP_2024_1_TRACKABLE_H
#define CPP_2024_1_TRACKABLE_H
#include <string>
#include "TrackableProtected.h"

class Trackable {
private:
    TrackableProtected *proc;
protected:
    const TrackableProtected* getProtected() const;
    TrackableProtected* getProtected();
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
