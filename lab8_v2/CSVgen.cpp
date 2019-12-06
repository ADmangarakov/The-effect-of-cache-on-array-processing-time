#include "pch.h"
#include "CSVgen.h"
#include <iostream>


CSVgen::CSVgen(char const * const fileName)
{

	if ((_access(fileName, 0)) == -1) {
		file_.open(fileName);
		file_ << 'N' << ';' << "averageTime" << std::endl;
	}
	else {
		file_.open(fileName, std::ios::app);
	}
}

void CSVgen::writeData(size_t size, ull time)
{
	file_ << size << ";" << time << std::endl;
}

CSVgen::~CSVgen()
{
	file_.close();
	std::cout << "delete CSVgen" << std::endl;
}
