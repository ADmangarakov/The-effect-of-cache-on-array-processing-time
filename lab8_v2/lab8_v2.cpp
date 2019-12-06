// lab8_v2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "TestArray.h"
#include "SparseArray.h"

int main()
{
	size_t const Nmin = 256;
	size_t const Nmax = 32 * 1024 * 1024 / 4;
	size_t K = 100;
	//for (size_t i = 0; i < 3; i++) {
	//	size_t step;
	//	for (size_t N = 256; N < Nmax; N += step) {
	//		Array* data = new Array(N, (TravOrder)i);
	//		TestArray randTrav(K, (TravOrder)i, data);
	//		randTrav.Test();
	//		step = N / 32;
	//		delete[] data;
	//	}
	//}
	size_t const offset = 16 * 1024 * 1024;
	size_t const size = 3 * 1024 * 1024;
	for (size_t i = 1; i < 32; i++) {
		SparseArray* data = new SparseArray(size, i, offset);
		TestArray offTest(K, ASSOCIATE, data);
		offTest.Test();
		delete[] data;
	}

}
