#include "pch.h"
#include "SparseArray.h"


SparseArray::SparseArray(size_t size, size_t blockNum, size_t offest)
	:size_(size)
	,blockNum_(blockNum)
	,offset_(offest)
	,array_(new unsigned[offest*blockNum])
{
	size_t block = 1;
	for (size_t i = 0, k = 0; i < size_; i++) {
		size_t nextIndex = (k + (block / blockNum_) + offset_);
		if (block/blockNum_) {
			nextIndex %= size_ / blockNum_;
		}
		array_[k] = nextIndex;
		k = nextIndex;
		++block;
	}
}

void SparseArray::RunTest(Timer & timer, size_t iter)
{
	for (size_t i = 0, k = 0; i < size_; i++) {
		k = array_[k];
	}

	for (size_t i = 0; i < iter; i++) {
		timer.StartTimer();
		for (size_t j = 0, k = 0; j < size_; j++) {
			k = array_[k];
		}
		timer.SaveIfMin();
	}
}


SparseArray::~SparseArray()
{
	delete[] array_;
}
