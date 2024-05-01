//
// Created by arnas on 3/24/24.
//

#ifndef CPP_2024_1_TRACKABLEPROTECTED_H
#define CPP_2024_1_TRACKABLEPROTECTED_H


class TrackableProtected {
public:
    static unsigned long NID;
    std::string Name;
    time_t Time;
    TrackableProtected(const TrackableProtected *tra);
    TrackableProtected(std::string name);
    TrackableProtected();
};


#endif //CPP_2024_1_TRACKABLEPROTECTED_H
