/* GCC extended ASM 
 *
 * Reference:
 * https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int src = 10;
	int dst;

	/* The basic format of extended asm . */
	/*
	asm ( 	assembler template
		: output operands                  // optional
		: input operands                   // optional
		: list of clobbered registers      // optional
	);
	*/

	/* This code copies src to dst and add 100 to dst.
	 *
	 * GCC will choose some register for input, one for output and does what we desired.
	 */
	asm (	"mov %1, %0\n\t"	// mov %dst, %src
		"add $100, %0"		// add $100, %src
		: "=r" (dst)		// output operand
		: "r" (src)		// input operand
	);

	printf("src: %d\n", src);
	printf("dst: %d\n", dst);

	return 0;
}
