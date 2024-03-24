//
// Created by arnas on 3/24/24.
//

#include <ctime>
#include <string>
#include "TrackableProtected.h"

TrackableProtected::TrackableProtected(const TrackableProtected *tra) : Time(tra->Time) {
Name = tra->Name;
}
unsigned long TrackableProtected::NID = 0;

TrackableProtected::TrackableProtected(std::string name) :Time(time(0)){
Name = name;

}

TrackableProtected::TrackableProtected() : Time(time(0)){

}
