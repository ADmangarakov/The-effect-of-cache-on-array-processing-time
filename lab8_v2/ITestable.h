#pragma once
#include "Timer.h"
class ITestable
{
public:
	virtual void RunTest(Timer& timer, size_t iter) = 0;
	virtual size_t getSize() const = 0;
	virtual size_t getN() const = 0;
	
	ITestable();
	virtual ~ITestable();
};

