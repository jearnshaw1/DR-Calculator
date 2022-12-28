#ifndef WAVELOADER_H

namespace dr_calculator
{
	class wave_loader
	{
	public:
		wave_loader(const char* fileName);

		~wave_loader();
		char* data{ nullptr };
		char* samples{ nullptr };
		int bitsPerSample{ 0 };
		int dataOffsetBytes{ 0 };
		int numSamples;

	};
}

#define WAVELOADER_H
#endif // WAVELOADER_H