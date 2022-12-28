#include "ImpulseGen.h"
#include <algorithm>
#include <cmath>
#include <fstream>

#ifndef PI
#define PI 3.14159265
#endif
/*
struct WaveLoadErr : public std::exception
{};

double sinc(double fc, int n)
{
	return 2 * fc * sin(2 * fc * PI * n) / (2 * fc * PI * n);
}

void generator(const char * fileName)
{
	std::fstream fileObject{ fileName, std::ios_base::in };

	if (fileObject.fail() | !fileObject.is_open())
		throw WaveLoadErr();

	for (int i = -50; i < 50; i++)
	{
		fileObject << sinc(0.02, i) ;
		fileObject << "\n";
	}
}
*/