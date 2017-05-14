/* GCC Common Variable Attributes: cleanup
 *
 * The cleanup attribute runs a function when the variable goes out of scope.
 * This attribute can only be applied to auto function scope variables; it may not be applied to
 * parameters or variables with static storage duration. The function must take one parameter, 
 * a pointer to a type compatible with the variable.
 * The return value of the function (if any) is ignored.
 *
 * Memory check: gcc -Wall -g cleanup_02.c && valgrind -v ./a.out
 *
 * References: https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html 
 */

#include <stdio.h>  
#include <stdlib.h>  

#define autofree __attribute((cleanup(__autofree)))  

void __autofree(void *p)  
{  
	void ** _p = (void **)p;  

	printf("free: %p\n", *_p);  
	free(*_p);  
}  

void * my_alloc(size_t size)  
{  
	void * ptr;  

	if ( ( ptr = malloc(size) ) == NULL )  
		exit(1);  
	
	printf("malloc: %p\n", ptr);  

	return ptr;  
}  

int main(int argc, char **argv)  
{
	int i;
	autofree char * x = my_alloc(32);  

	for (i = 0; i < 1; i++){  
		autofree int *y = my_alloc(64);  
		printf("y: %p\n", y);  
	}  

	printf("x: %p\n", x);  

	return 0;
}  

