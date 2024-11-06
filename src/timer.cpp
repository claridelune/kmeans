#include "../include/timer.h"
#include <chrono>

Timer::Timer() : start(std::chrono::high_resolution_clock::now()) {}

double Timer::elapsed() const {
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}
