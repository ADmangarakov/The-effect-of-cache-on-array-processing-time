#pragma once
#include "Timer.h"
class ITestable
{
public:
	virtual void RunTest(Timer& timer, size_t iter) = 0;
	ITestable();
	virtual ~ITestable();
};

