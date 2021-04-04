
// DR Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include "windows.h"
#include  <cstdio>
#include "WaveLoader.h"

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{

		printf("The path to a wave file was not specified\n");

		return 1;

	}

	else if (argc > 2) 
	{

		printf("Too many arguments supplied.\n");

		return 1;

	}



	waveloader waveloader1(argv[0]);

	R128(waveloader1&);

	return 0;
}

