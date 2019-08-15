#include "timer.h"

void Timer::Init(){
    clock_gettime(CLOCK_REALTIME, &begin_);
}

timespec Timer::GetTime(){
    struct timespec time_now;
    clock_gettime(CLOCK_REALTIME, &time_now);
    return time_now;
}

long long Timer::GetTimeElapsed(){
    timespec time_now = GetTime();
    long long time_cost = GetTimeElapsed(begin_, time_now);
    begin_ = time_now;
    return time_cost;
}

long long Timer::GetTimeElapsed(const timespec &begin, const timespec &end){
    long long time_cost = (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_nsec - begin.tv_nsec) / 1000000;
    return time_cost;
}
