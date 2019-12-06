#include "pch.h"
#include "TestArray.h"
#include <iostream>



TestArray::TestArray(size_t iter, TravOrder key, ITestable* testData)
	:iter_(iter)
	, key_(key)
	, testArray_(testData)
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
	case ASSOCIATE:
		document_ = new CSVgen("associate.csv");
		break;
	}
}

void TestArray::Test()
{
	testArray_->RunTest(timer_, iter_);
	document_->writeData(testArray_->getN(), timer_.getTime() / testArray_->getSize());
}


TestArray::~TestArray()
{
	std::cout << "delete testArray" << std::endl;
	delete document_;
}
