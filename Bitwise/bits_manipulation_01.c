/* bits manipulation
 *
 * We have following functions to manipulate the bits of a register.
 * SET_ALL_BITS(), SET_SPECFIC_BIT(), CLEAR_SPECFIC_BIT(), TOGGLE_SPECFIC_BIT(), TEST_SPECFIC_BIT()
 */

#include <stdio.h>

// print integer in binary for 8-bits
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c\n"

// convert binary number to char
#define BYTE_TO_BINARY(byte)  		\
	(byte & 0x80 ? '1' : '0'), 	\
	(byte & 0x40 ? '1' : '0'), 	\
	(byte & 0x20 ? '1' : '0'), 	\
	(byte & 0x10 ? '1' : '0'), 	\
	(byte & 0x08 ? '1' : '0'), 	\
	(byte & 0x04 ? '1' : '0'), 	\
	(byte & 0x02 ? '1' : '0'), 	\
	(byte & 0x01 ? '1' : '0')

#define SET_ALL_BITS(x, y)		( (x) = (y) )
#define SET_SPECFIC_BIT(x, y)		( (x) |= (y) )
#define CLEAR_SPECFIC_BIT(x, y)         ( (x) &= ~(y) )
#define TOGGLE_SPECFIC_BIT(x, y)        ( (x) ^= (y) )
#define TEST_SPECFIC_BIT(x, y)          ( (x) &= (y) )

int main()
{
        int a = 0b00000000;             // original
	int b = 0b11110000;		// set all bits
        int c = 0b01010101;             // set specific bits
        int d = 0b01010000;             // clear specific bits
        int e = 0b00001111;             // toggle specific bits
        int f = 0b00001111;             // test specific bits

	printf("#define SET_ALL_BITS(x, y)		( (x) = (y) )\n");
	printf("#define SET_SPECFIC_BIT(x, y)		( (x) |= (y) )\n");
	printf("#define CLEAR_SPECFIC_BIT(x, y)         ( (x) &= ~(y) )\n");
	printf("#define TOGGLE_SPECFIC_BIT(x, y)        ( (x) ^= (y) )\n");
	printf("#define TEST_SPECFIC_BIT(x, y)          ( (x) &= (y) )\n");


        printf("\n");
        printf("a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        printf("b: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(b));
        printf("c: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));
        printf("d: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(d));
        printf("e: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(e));
        printf("f: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(e));
        printf("\n");

        printf("before SET_ALL_BITS(a, b), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        SET_ALL_BITS(a, b);
        printf("after  SET_ALL_BITS(a, b), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        printf("\n");

	printf("before SET_SPECFIC_BIT(a, c), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
	SET_SPECFIC_BIT(a, c);
	printf("after  SET_SPECFIC_BIT(a, c), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
	printf("\n");

        printf("before CLEAR_BIT(a, d), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        CLEAR_SPECFIC_BIT(a, d);
        printf("after  CLEAR_BIT(a, d), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        printf("\n");

        printf("before TOGGLE_BIT(a, e), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        TOGGLE_SPECFIC_BIT(a, e);
        printf("after  TOGGLE_BIT(a, e), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        printf("\n");

        printf("before TEST_BIT(a, f), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        TEST_SPECFIC_BIT(a, f);
        printf("after  TEST_BIT(a, f), a: "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(a));
        printf("\n");

        return 0;
}
