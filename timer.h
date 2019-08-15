#pragma once

#include<time.h>

class Timer {
    public:
        void Init();
        timespec GetTime();
        long long GetTimeElapsed();
        long long GetTimeElapsed(const timespec &begin, const timespec &end);
    private:
        timespec begin_;
};
