/* Make a signed overflow occurs, and check the eflag, OF, from the GDB.
 *
 * CF: It indicates when an arithmetic carry or borrow has been generated out of the most
 * significant ALU bit position.
 *
 * PF: It indicates if the number of set bits is odd or even in the binary representation 
 * of the result of the last operation.
 * 
 * AF: It indicates when an arithmetic carry or borrow has been generated out of the four 
 * least significant bits, or lower nibble. It is primarily used to support binary-coded 
 * decimal arithmetic.
 *
 * ZF: Zero Flag. The most recent operation yielded zero.
 *
 * SF: Sign Flag. The most recent operation yielded a negative value.
 *
 * IF: It determines whether or not the CPU will handle maskable hardware interrupts.
 *
 * OF: Overflow Flag. The most recent operation caused a two’s-complement overflow—either 
 * negative or positive.
 *
 *
 * GDB USAGE:
 *
 * (gdb) break main
 * (gdb) run
 * (gdb) n
 * (gdb) n
 *
 * (gdb) info reg eflags
 * eflags         0x246    [ PF ZF IF ]
 * (gdb) n
 * 
 * (gdb) info reg eflags
 * eflags         0xa92    [ AF SF IF OF ]
 *
 */

#include <stdio.h>

int main()
{

	int a = 2147483647;
	int b = 9;
	int c = 3;

	a += b;
	b += c;

	return 0;
}
