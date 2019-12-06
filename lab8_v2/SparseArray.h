#pragma once
#include "ITestable.h"
class SparseArray :
	public ITestable
{
	size_t size_;
	size_t blockNum_;
	size_t offset_;
	unsigned* array_;
public:
	SparseArray(size_t size, size_t blockNum, size_t offest);
	void RunTest(Timer& timer, size_t iter);
	size_t getSize() const
	{
		return size_;
	}
	size_t getN() const
	{
		return blockNum_;
	}

	~SparseArray();
};

