/* A simple function to copy the specified i-bit from one integer to another.
 * The i-bit is zero based.
 */


#include <stdio.h>

int copy_specified_bit (int a, int b, unsigned i_th)
{
	int a_i = ( a >> i_th ) & 0x1;
	int b_i = ( b >> i_th ) & 0x1;

	if (a_i != b_i)
		return (a ^= (0x1 << i_th));
	else
		return a;
}

int main()
{
	// 12: 0b1100, 7: 0b0111, copy_bit(12, 7, 3) = 4, 4: 0b0100
	printf("copy_specified_bit(12, 7, 3): %d\n", copy_specified_bit(12, 7, 3));
	printf("copy_specified_bit(-12, -7, 3): %d\n", copy_specified_bit(-12, -7, 3));

	return 0;
}
