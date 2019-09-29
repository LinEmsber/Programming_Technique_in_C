#include <stdio.h>

unsigned int abs_original(int x)
{
	return ( x < 0 ) ? -x : x;
}

unsigned int sex(int x)
{
	return x >> (__CHAR_BIT__ * sizeof(int) - 1);
}


unsigned int abs_optimized_1(int x)
{
	return ( x ^ sex(x) ) - sex(x);
}

int main()
{

	printf("abs_original(-100): %d", abs_original(-100));
	printf("abs_optimized_1(-100): %d", abs_optimized_1(-100));

	return 0;
}
