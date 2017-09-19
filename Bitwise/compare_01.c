#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Use the feature of two's complement to compare two 32bit signed integer.
 * If (x - y) > 0, return 1
 * If (x - y) = 0, return 0
 * If (x - y) < 0, return 2
 *
 * Explnantion:
 * If diff > 0, (!!diff) = 1, (diff >> 31) = 0, (diff >> 31) & 1 = 0
 * If diff = 0, (!!diff) = 0, (diff >> 31) = 0, (diff >> 31) & 1 = 0
 * If diff < 0, (!!diff) = 1, (diff >> 31) = 1, (diff >> 31) & 1 = 1
 */
int compare_int32(int32_t x, int32_t y)
{
	int diff = x - y;
	return (!!diff) << ((diff >> 31) & 1);
}


int main()
{
	printf("compare_int32(10, 5): %d\n", compare_int32(10, 5));
	printf("compare_int32(10, 10): %d\n", compare_int32(10, 10));
	printf("compare_int32(10, 15): %d\n", compare_int32(10, 15));

	return 0;
}
