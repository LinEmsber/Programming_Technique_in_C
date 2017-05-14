/* GCC Common Type Attributes: packed
 *
 * References: https://gcc.gnu.org/onlinedocs/gcc/Common-Type-Attributes.html#Common-Type-Attributes 
 */

#include <stdio.h>
#include <stdlib.h>


/* structure */
struct struct_a{
	char a;
	int b;
	char c;
};


struct struct_b{
	char a;
	int b;
	char c;
} __attribute__((packed));


int main()
{
	printf("\nstruct struct_a{\n\tchar a;\n\tint b;\n\tchar c;\n};\n");
	printf("\nstruct struct_a{\n\tchar a;\n\tint b;\n\tchar c;\n}__attribute__((packed));\n\n");

	printf("sizeof(struct struct_a): %zu\n", sizeof(struct struct_a));
	printf("sizeof(struct struct_b): %zu\n", sizeof(struct struct_b));

	return 0;
}

