#pragma once
#include "ITester.h"
#include "Timer.h"
#include "CSVgen.h"
#include "Array.h"
class TestArray :
	public ITester
{
	size_t iter_;
	TravOrder key_;

	Timer timer_;
	CSVgen* document_;
	ITestable* testArray_;

	TestArray(TestArray const & a);
public:
	TestArray(size_t iter, TravOrder key, ITestable * testData);
	void Test();
	~TestArray();
};

