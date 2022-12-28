#include  <cstdio>
#include "dr_calculator/wave_loader.h"

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		return 1;
	}
	else if (argc > 2) 
	{
		return 1;
	}

	dr_calculator::wave_loader WaveLoader(argv[0]);

	return 0;
}

