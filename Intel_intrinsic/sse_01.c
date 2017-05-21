/* The simple demonstration of Intel intrinsics: SSE
 *
 * USAGE: gcc -Wall -g -msse sse_01.c && ./a.out
 *
 * https://software.intel.com/sites/landingpage/IntrinsicsGuide/
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mmintrin.h>
#include <xmmintrin.h>


/* The number of elements we would need in an float array to hold an m128.
 * Because 128 / 32 = 4, so it should be 4.
 */
#define FLOAT_ARRAY_SIZE (sizeof(__m128) / sizeof(float))

void f2c_sse(float * src_array, float * dst_array, size_t array_len)
{
	__m128 celsius_vector, fahrenheit_vector, partial_vector;
	__m128 coeff_vector;

	const __m128 thirtytwo_vector = {32.0, 32.0, 32.0, 32.0};

	/* set coeff_vector */
	coeff_vector = _mm_set1_ps(9.0 / 5.0);

	/* load src_array into celsius_vector  */
	celsius_vector = _mm_load_ps(src_array);

	/* set partial_vector as the product of 9/5 * C  */
	partial_vector = _mm_mul_ps(celsius_vector, coeff_vector);

	/* add 32 to all elements of partial_vector */
	fahrenheit_vector =  _mm_add_ps(partial_vector, thirtytwo_vector);

	/* copy fahrenheit_vector into dst_array  */
	_mm_store_ps(dst_array, fahrenheit_vector);
}


int main (int argc, char * argv[])
{
	int i;

	float celsius_array[]  __attribute__ ((aligned (16))) = {-100.0, -80.0, -40.0, 0.0};
	float fahrenheit_array[FLOAT_ARRAY_SIZE] __attribute__ ((aligned (16)));

	f2c_sse(celsius_array, fahrenheit_array, sizeof(celsius_array));

	/* print out the results.  */
	for (i = 0; i < FLOAT_ARRAY_SIZE; i++)
		printf("%f celsius is %f fahrenheit\n", celsius_array[i], fahrenheit_array[i]);

	return(0);
}
