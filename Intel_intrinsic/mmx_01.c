/* The simple demonstration of Intel intrinsics: MMX
 *
 * USAGE: gcc -Wall -g -mmmx mmx_01.c && ./a.out
 *
 * References:
 * https://software.intel.com/en-us/node/524281
 * https://software.intel.com/sites/landingpage/IntrinsicsGuide/
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <mmintrin.h>


/* The number of elements we would need in an int16_t array to hold an m64.
 * Because 64 / 16 = 4, so it should be 4.
 */
#define SHORT_ARRAY_SIZE (sizeof(__m64) / sizeof(int16_t))


/* Convert the temperatures in Fahrenheit degree to Celsius degree. */
void f2c_mmx(int16_t * src_array, int16_t * dst_array, size_t array_len)
{
	int coefficient;

	__m64 celsius_vector, fahrenheit_vector, partial, coef_vector;
	const __m64 thirtytwo_vector = _mm_set_pi16(32, 32, 32, 32);

	/* load the values from src_array into celsius_vector */
	celsius_vector = *( (__m64 *)src_array );

	/* The cofficient, and cast it integer.
	 * We use (9 * 64) / 5, and we will do 6 bits right shift later.
	 */
	coefficient = ( (9 * 64) / 5);

	/* Broadcast 16-bit integer a to all all elements of dst. */
	coef_vector = _mm_set1_pi16(coefficient );

	/* multiply all elements of coef_vector by celsius_vector. */
	partial = _mm_mullo_pi16(coef_vector, celsius_vector);

	/* 6 bits right shift.
	 * After this, each element of partial will be about 9/5 * C  */
	partial = _mm_srai_pi16(partial, 6);

	/* Add the vector of 32's onto partial. */
	fahrenheit_vector = _mm_add_pi16(partial, thirtytwo_vector);

	/* copy the fahrenheit_vector into an array, so we can print it. */
	memcpy(dst_array, &fahrenheit_vector, array_len);

	/* Empty the MMX state, which marks the x87 FPU registers as available for use by x87 instructions.
	 * This instruction must be used at the end of all MMX technology procedures.
	 */
	_mm_empty();
}


int main (int argc, char * argv[])
{
	int i;

	int16_t celsius_array[] __attribute__ ( (aligned (16)) ) = {-100, -80, -40, 0};
	int16_t fahrenheit_array[SHORT_ARRAY_SIZE] __attribute__ ( (aligned (16)) );

	f2c_mmx(celsius_array, fahrenheit_array, sizeof(celsius_array));

	/* print */
	for (i = 0; i < SHORT_ARRAY_SIZE; i++)
		printf("%d celsius is %d fahrenheit\n", celsius_array[i], fahrenheit_array[i]);

	return(0);
}
