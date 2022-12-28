#ifndef IMPULSEGEN_H
#define IMPULSEGEN_H

namespace dr_calculator
{
	double sinc(double, int);
	void generator(const char *, double(*func)(double, int));
} 

#endif //IMPULSEGEN_H
