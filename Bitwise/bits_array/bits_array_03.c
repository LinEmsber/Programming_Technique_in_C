/* Use integer array to represent a sequence of bits array.
 * It can be used for dynamic programming to record the boolean results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SET_BIT(A,k)     ( A[(k / 32)] |= (1 << (k % 32)) )
#define CLEAR_BIT(A,k)   ( A[(k / 32)] &= ~(1 << (k % 32)) )
#define TEST_BIT(A,k)    ( A[(k / 32)] & (1 << (k % 32)) ) ? 1 : 0

int main()
{
        // 5 * 32 = 160 bits
        unsigned int * bits_array = (unsigned int *) malloc( sizeof(unsigned int) * 5);
        memset(bits_array, 0, sizeof(unsigned int)*5);

        printf("TEST_BIT(bits_array, 50): %d\n", TEST_BIT(bits_array, 50));

        SET_BIT(bits_array, 10);
        SET_BIT(bits_array, 30);
        SET_BIT(bits_array, 50);
        SET_BIT(bits_array, 70);

        printf("TEST_BIT(bits_array, 50): %d\n", TEST_BIT(bits_array, 50));

        CLEAR_BIT(bits_array, 10);
        CLEAR_BIT(bits_array, 50);

        printf("TEST_BIT(bits_array, 50): %d\n", TEST_BIT(bits_array, 50));

        return 0;
}
