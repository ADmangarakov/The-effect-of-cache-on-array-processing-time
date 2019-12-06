#pragma once
#include <fstream>
#include <io.h>

typedef unsigned long long ull;
class CSVgen
{
	std::ofstream file_;
public:
	CSVgen(char const*const fileName);
	void writeData(size_t size, ull time);
	~CSVgen();
};

