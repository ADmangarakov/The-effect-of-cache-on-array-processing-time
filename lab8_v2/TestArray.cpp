#include "pch.h"
#include "TestArray.h"




TestArray::TestArray(size_t sizeMAX, size_t sizeMIN, size_t iter, TravOrder key)
	:sizeMAX_(sizeMAX)
	, sizeMIN_(sizeMIN)
	, iter_(iter)
	, key_(key)
{
	switch (key) {
	case FRONT:
		document_ = new CSVgen("front_trav.csv");
		break;
	case BACK:
		document_ = new CSVgen("back_trav.csv");
		break;
	case RAND:
		document_ = new CSVgen("rand_trav.csv");
		break;
	}
}

void TestArray::Test()
{
	size_t step = 0;
	for (size_t N = sizeMIN_; N < sizeMAX_; N += step) {
		testArray_ = new Array(N, key_);
		testArray_->RunTest(timer_, iter_);
		makeReport(N);
		step = N / 32;
	}
}


void TestArray::makeReport(size_t size)
{
	document_->writeData(size, timer_.getTime() / size);
}


TestArray::~TestArray()
{
	delete document_;
}
