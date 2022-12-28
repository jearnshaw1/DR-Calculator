#include "WaveLoader.h"
#include <fstream>
#include <istream>
#include <exception>
#include <iostream>

namespace WaveLoader
{
	struct WaveLoadErr : public std::exception
	{};

	WaveLoader::WaveLoader(const char* fileName)
	{
		//std::ifstream fileObject( fileName, std::ios_base::in );

		std::ifstream fileObject;
		fileObject.open("Lonely_Love_MASTER_4832.wav");

		if (fileObject.fail() || !fileObject.is_open())
			throw WaveLoadErr();

		// read file header according to sox convention


		data = new char[36];
		// Big endian is fine , little end. not interpreted correctly
		//ASSERT(sizeof(char) == 1);
		fileObject.read(data, 36);

		// bits per sample segment is little end;
		if (data[34] == 0x10)
		{
			bitsPerSample = 16;
		}
		else if (data[34] == 0x18)
		{
			bitsPerSample = 24;
		}

		else if (data[34] == 0x20)
		{
			bitsPerSample = 32;
		}
		else
		{
			std::cout << "The bit depth is " << data[34] << "and the file cannot be read\n";


		}
		dataOffsetBytes = 44;
		int numberSampleBytes{ data[40] };
		samples = new char[numberSampleBytes];

		fileObject.seekg(44, std::ios_base::beg);
		fileObject.read(samples, numberSampleBytes);

		numSamples = numberSampleBytes / (2 * bitsPerSample);
	}

	WaveLoader::~WaveLoader()
	{
		delete[] data;
		delete[] samples;
	}
}



