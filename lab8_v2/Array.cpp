#include "pch.h"
#include "Array.h"


Array::Array(size_t size, TravOrder key)
	:size_(size)
	, array_(new unsigned[size_])
{
	switch (key) {
	case FRONT:
		for (size_t i = 0; i < size_; i++) {
			array_[i] = (i + 1) % size_;
		}
		break;
	case BACK:
		for (size_t i = 0; i < size_; i++) {
			array_[i] = (size_ - 1 + i) % size_;
		}
		break;
	case RAND:
		randTrav();
		break;
	}
}

void Array::RunTest(Timer & timer, size_t iter)
{
	for (size_t i = 0, k = 0; i < size_; i++) {
		k = array_[k];
	}

	for (size_t i = 0; i < iter; i++) {
		timer.StartTimer();
		for (size_t i = 0, k = 0; i < size_; i++) {
			k = array_[k];
		}
		timer.SaveIfMin();
	}
}

void Array::randTrav()
{
	unsigned* perm = new unsigned[size_];
	for (size_t i = 0; i < size_; i++) {
		perm[i] = i;
	}
	for (size_t i = 0; i < size_; i++) {
		unsigned j = std::rand() % (size_ - i);
		std::swap(perm[i], perm[j]);
	}
	size_t k = 0;
	for (size_t i = 0; i < size_; i++) {
		k = perm[i];
		array_[k] = perm[(i + 1) % size_];
	}
	delete[] perm;
}


Array::~Array()
{
	delete[] array_;
}
