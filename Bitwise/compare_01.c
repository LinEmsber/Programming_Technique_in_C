/* A function or macro to compare 32 bit signed integer and output the result. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Use the feature of two's complement to compare two 32 bit signed integer.
 * If (x - y) > 0, return 1
 * If (x - y) = 0, return 0
 * If (x - y) < 0, return 2
 *
 * Explnantion:
 * If diff > 0, (!!diff) = 1, (diff >> 31) = 0, (diff >> 31) & 1 = 0
 * If diff = 0, (!!diff) = 0, (diff >> 31) = 0, (diff >> 31) & 1 = 0
 * If diff < 0, (!!diff) = 1, (diff >> 31) = 1, (diff >> 31) & 1 = 1
 */

/* Macro */
#define COMPARE_INT32(x, y) ( !!(x - y) ) << ( ( (x - y) >> 31 ) & 1 )

/* Complex function */
int compare_int32(int32_t x, int32_t y)
{
	int diff = x - y;
	return (!!diff) << ((diff >> 31) & 1);
}

/* Naive function */
int normal_compare_int32(int32_t x, int32_t y)
{
	if (x > y)
		return 1;
	else if ( x == y)
		return 0;
	else
		return 2;
}


int main()
{
	int a, b;

	printf("compare_int32(0xdefa, 0xfeda): %d\n", normal_compare_int32(0xdefa, 0xfeda));
	printf("compare_int32(10, 10): %d\n", compare_int32(0x99, 0x88));
	printf("compare_int32(10, 15): %d\n", compare_int32(10, 15));

	printf("compare_int32(0xdefa, 0xfeda): %d\n", compare_int32(0xdefa, 0xfeda));
	printf("compare_int32(10, 10): %d\n", compare_int32(100, 10));
	printf("compare_int32(10, 15): %d\n", compare_int32(15, 15));

	printf("compare_int32(0xdefa, 0xfeda): %d\n", COMPARE_INT32(0xdefa, 0xfeda));
	printf("compare_int32(10, 10): %d\n", COMPARE_INT32(10, 10));
	printf("compare_int32(10, 15): %d\n", COMPARE_INT32(150, 150));

	return 0;
}
