/* GCC Extensions to the C Language Family
 * GNU C provides several language features not found in ISO standard C.
 *
 * Using Vector Instructions through Built-in Functions
 *
 * GCC attribute: vector_size
 *
 * The int type specifies the base type, while the attribute specifies the vector size for the variable,
 * measured in bytes. For example, the declaration above causes the compiler to set the mode for the v4si
 * type to be 16 bytes wide and divided into int sized units.
 *
 * For a 32-bit int this means a vector of 4 units of 4 bytes, and the corresponding mode of foo is V4SI.
 *
 * References:
 * https://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>


/* The below expression is the original type definition from the GCC's mmintrin.h, which declare the type
 * and functions of Intel intrinsics: MMX.
 * path: /usr/lib/gcc/x86_64-linux-gnu/5/include/
 *
 * typedef int __m64 __attribute__ ((__vector_size__ (8), __may_alias__));
 *
 * The 64 of __m64 represents the vector size is 8 byte, as well as 8 * 8bits = 64bits.
 */

/* 128 bits = 16 * 8 bits */
typedef int __m128_t __attribute__ ((__vector_size__(16), __may_alias__));

int main()
{
	int i;

	__m128_t __m128_vector;
	size_t array_size = sizeof(__m128_t) / sizeof(int8_t);

	int8_t dst_array[array_size] __attribute__ ( (aligned(8)) );
	int8_t src_array[] __attribute__ ( (aligned(8)) ) = {0, 1, 2, 3, 4, 5, 6, 7,
								8, 9, 10, 11, 12, 13, 14, 15};

	/* assign the value of src_array into __m128_vector which's data type is __m128_t. */
	__m128_vector = *( (__m128_t *) src_array);

	/* copy from __m128_vector to an array, so we can print it. */
	memcpy(dst_array, &__m128_vector, sizeof(__m128_t));

	/* print the result */
	for (i = 0; i < array_size; i++)
		printf("dst_array[%d]: %d\n", i, dst_array[i]);

	return 0;
}
