#ifndef PROJECT_2_SDIZO_TIME_H
#define PROJECT_2_SDIZO_TIME_H

#include <chrono>
#include <iostream>


using namespace std;
using namespace std::chrono;


// klasa czasu
class Time
{

private:
    high_resolution_clock::time_point start; // czas poczatkowy
    high_resolution_clock::time_point stop; // czas koncowy

public:
    Time();
    ~Time();
    void start_time();
    void stop_time();
    long long time();

};
#endif
