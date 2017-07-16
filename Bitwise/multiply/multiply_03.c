#include <stdio.h>

int loop_counter = 0;

/*	multiply (a=-6, b=18), loop_counter = 1
	multiply (a=-12, b=9), loop_counter = 2
	multiply (a=-24, b=4), loop_counter = 3
	multiply (a=-48, b=2), loop_counter = 4
	multiply (a=-96, b=1), loop_counter = 5
	multiply (a=-192, b=0), loop_counter = 6

	When the integers 1 and 9 are odd numbers:
	(gdb) p 1 << 31 >> 31
	$1 = 11111111111111111111111111111111
	(gdb) p 9 << 31 >> 31
	$1 = 11111111111111111111111111111111

	When the integers 2, 4, and 18 are even numbers:
	(gdb) p 2 << 31 >> 31
	$1 = 0
	(gdb) p 4 << 31 >> 31
	$1 = 0
	(gdb) p 18 << 31 >> 31
	$1 = 0
*/

int multiply(int a, int b)
{
	loop_counter++;
	if (!a || !b)
		return 0;

	return multiply( a << 1, b >> 1 ) + ( a & ( b << 31 >> 31) );
}

int main()
{
	int x = -6;
	int y = 18;
	int ans = multiply(x, y);
	printf("x * y: %d\n", ans );
	printf("loop_counter: %d\n", loop_counter );
}
