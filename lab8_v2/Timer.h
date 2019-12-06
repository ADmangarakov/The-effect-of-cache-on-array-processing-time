#pragma once
#include <intrin.h>
typedef unsigned long long ull;
class Timer
{
	ull time_;
	ull min_time_;
public:
	Timer();
	void StartTimer();
	void SaveIfMin();
	ull getTime() const;
	~Timer();
};

