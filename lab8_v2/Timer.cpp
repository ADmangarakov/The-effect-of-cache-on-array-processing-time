#include "pch.h"
#include "Timer.h"


Timer::Timer()
	:time_(0)
	, min_time_(0)
{
}

void Timer::StartTimer()
{
	time_ = __rdtsc();
	min_time_ = 0;
}

void Timer::SaveIfMin()
{
	ull dif = __rdtsc() - time_;
	if (dif < min_time_ || min_time_ == 0) {
		min_time_ = dif;
	}
}

ull Timer::getTime() const
{
	return min_time_;
}


Timer::~Timer()
{
}
