#include  <cstdio>
#include "dr_calculator/wave_loader.h"
#include <cassert>

int main(int argc, char* argv[])
{
	dr_calculator::wave_loader WaveLoader;

	WaveLoader.load( "tone_4416.wav" );

	return 0;
}

