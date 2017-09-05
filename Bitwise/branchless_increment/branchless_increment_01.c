/* Use the feature of two's complement to do branchless increment or decrement. */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
	int32_t a, b, c, d;

	a = 3;
	b = -5;
	c = 7;
	d = -9;

	// if ( a < 0 ) a++;
	a -= a >> 31;	// a = 4

	// if ( b < 0 ) b++;
	b -= b >> 31;	// b = -4

	// if ( c < 0 ) c--;
	c += c >> 31;	// c = 7

	// if ( d < 0 ) d--;
	d += d >> 31;	// d = -8

	/* Another method. */
	a += ( (a & 0x80000000) >> 7 );
	a += ( (a >> 31) & 0x1 );

	return 0;
}
