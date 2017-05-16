/* GCC Common Variable Attributes: aligned
 *
 * USAGE: gcc -O0 -Wall -g aligned_01.c && ./a.out
 *
 * References: https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes
 */

#include <stdio.h>

int main(void)
{
	float a[4] = { 100.0, 200.0, 300.0, 400.0 };
	float b[4] __attribute__((aligned(0x1000))) = { 100.0, 200.0, 300.0, 400.0 };
	float c[4] __attribute__((aligned(0x10000))) = { 100.0, 200.0, 300.0, 400.0 };

	printf("No aligned: \t\t%p %p %p %p\n", &a[0], &a[1], &a[2], &a[3]);
	printf("Aligned 0x1000: \t%p %p %p %p\n", &b[0], &b[1], &b[2], &b[3]);
	printf("Aligned 0x10000: \t%p %p %p %p\n", &c[0], &c[1], &c[2], &c[3]);
}
