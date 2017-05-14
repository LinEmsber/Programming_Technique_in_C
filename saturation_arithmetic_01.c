/* The addition of saturation arithmetic 
 *
 * It is possible make a instruction to conduct saturation arithmetic ?
 *
 * If ( CF && OF )
 * 
 * JSA uint16_max, %eax
 *
 */

#include <stdio.h>
#include <stdint.h>


uint16_t sadd16(uint16_t a, uint16_t b)
{
	return (a > 0xFFFF - b) ? 0xFFFF : a + b;
}

uint32_t sadd32(uint32_t a, uint32_t b)
{
	return (a > 0xFFFFFFFF - b) ? 0xFFFFFFFF : a + b;
}

int main()
{
	int counter = 0;

	uint16_t answer = 1;
	uint16_t prev_answer;

	while(1){
		prev_answer = answer;

		answer = sadd16(answer, answer);

		if (prev_answer == answer)
			break;

		counter++;
	}

	printf("answer: %d, counter: %d\n", answer, counter);

	return 0;
}
