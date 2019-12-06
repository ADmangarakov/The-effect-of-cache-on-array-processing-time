#pragma once
#include "ITester.h"
#include "Timer.h"
#include "CSVgen.h"
#include "Array.h"
class TestArray :
	public ITester
{
	size_t sizeMAX_;
	size_t sizeMIN_;
	size_t iter_;
	TravOrder key_;

	Timer timer_;
	CSVgen* document_;
	Array* testArray_;

	void makeReport(size_t size);

	TestArray(TestArray const & a);
public:
	TestArray(size_t sizeMAX, size_t sizeMIN, size_t iter, TravOrder key);
	void Test();
	~TestArray();
};

