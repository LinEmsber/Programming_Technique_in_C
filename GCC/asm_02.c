/* GCC extended ASM
 *
 * Reference:
 * http://www.osdever.net/tutorials/view/a-brief-tutorial-on-gcc-inline-asm
 * https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 5;
	int five_times_x = 0;

	/* We want to multiply a number by 5. For that we use the instruction lea. */
        asm (	"leal (%1,%1,4), %0"
		: "=r" (five_times_x)
		: "r" (x)
	);

	printf("x: %d\nfive_times_x: %d\n", x, five_times_x);


	/* We want the input and output to reside in the same register.
	 *
	 * All outputs must be marked with "=", which says that this operand is assigned to.
	 */
        asm (	"leal (%0,%0,4), %0"
		: "=r" (five_times_x)
		: "0" (x)
	);

	printf("x: %d\nfive_times_x: %d\n", x, five_times_x);


	/* We want to specify which register to use. */
	asm (	"leal (%%ecx,%%ecx,4), %%ecx"
		: "=c" (x)
		: "c" (x)
	);

	printf("x: %d\nfive_times_x: %d\n", x, five_times_x);


	return 0;
}
