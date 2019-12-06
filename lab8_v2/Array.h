#pragma once
#include <algorithm>
#include "ITestable.h"

enum TravOrder
{
	FRONT,
	BACK,
	RAND,
	ASSOCIATE
};

class Array : public ITestable
{
	size_t size_;
	unsigned* array_;

	void randTrav();
	Array(Array const& arr);
public:
	Array(size_t size, TravOrder key);
	void RunTest(Timer& timer, size_t iter);
	size_t getSize() const
	{
		return size_;
	}
	size_t getN() const;
	~Array();
};

