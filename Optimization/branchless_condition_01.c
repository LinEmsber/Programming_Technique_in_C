#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int foo(int x)
{
	if(4 == x)
		return 54;
	else
		return 2;
}

int foo_optimization(int x)
{
	int eax;
	eax = x - 4;
	eax = -(eax != 0); //See below
	eax = (eax & -52) + 54;
	return eax;
}


int main()
{
	// assert( foo(4) == foo_optimization(4) );
        // printf("foo(4): %d\n", foo(4));
        // printf("foo_optimization(4): %d\n", foo_optimization(4));

	// assert( foo(12) == foo_optimization(12) );
        // printf("foo(12): %d\n", foo(12));
        // printf("foo_optimization(12): %d\n", foo_optimization(12));

	return 0;
}
