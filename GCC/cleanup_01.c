/* GCC Common Variable Attributes: cleanup
 *
 * Memory check: gcc -Wall -g cleanup_01.c && valgrind -v ./a.out
 *
 * References: https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html 
 */

#include <stdio.h>
#include <stdlib.h>

#define autofree __attribute__( (cleanup(__auto_free)) )

void __auto_free(void *p) 
{
	free( *(void **) p );
}

int main()
{
	autofree int * i = malloc( sizeof (int) );

	autofree char * string = malloc( sizeof(char) * 16);

	return 0;
}
