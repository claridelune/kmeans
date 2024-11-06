#ifndef TIMER_H
#define  TIMER_H

#include <chrono>

class Timer {
    public:
        Timer();
        double elapsed() const;
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

#endif
