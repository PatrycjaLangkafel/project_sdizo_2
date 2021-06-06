#include "Time.h"


using namespace std;
using namespace std::chrono;

// konstruktor
Time :: Time(){}

// destruktor
Time :: ~Time() {}

// funkcja przypisujaca wartosc czasu poczatkowego
void Time :: start_time()
{
    start = high_resolution_clock::now();
}

// funkcja przypisujaca wartosc czasu koncowego
void Time :: stop_time()
{
    stop = high_resolution_clock::now();
}

// funkcja zwracajaca wartosc czasu wykonania okreslonej metody
long long Time :: time()
{
    return duration_cast<nanoseconds>(stop - start).count();
}
