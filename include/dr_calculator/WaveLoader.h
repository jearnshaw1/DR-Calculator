#ifndef WAVELOADER_H
namespace WaveLoader
{

	class WaveLoader
	{
	public:
		WaveLoader(const char* fileName);

		~WaveLoader();
		char* data{ nullptr };
		char* samples{ nullptr };
		int bitsPerSample{ 0 };
		int dataOffsetBytes{ 0 };
		int numSamples;

	};

}
#define WAVELOADER_H
#endif // WAVELOADER_H