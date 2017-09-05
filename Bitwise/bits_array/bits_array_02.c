/* Use integer array to represent a sequence of bits array.
 * It can be used for dynamic programming to record the boolean results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  set_bit(int * A,  int k)
{
        A[k / 32] |= ( (unsigned int)0x1 << (k % 32) );
}

void  clear_bit(int * A,  int k)
{
        A[k / 32] &= ~ ( (unsigned int) 0x1 << (k % 32) );
}

int test_bit(int * A,  int k)
{
        return ( A[k / 32] & ( (unsigned int) 0x1 << (k % 32) ) ) != 0;
}

int main()
{
        // 5 * 32 = 160 bits
        int * bits_array = (int *) malloc( sizeof(int) * 5);
        memset(bits_array, 0, sizeof(int)*5);

        printf("test_bit(bits_array, 50): %d\n", test_bit(bits_array, 50));

        set_bit(bits_array, 10);
        set_bit(bits_array, 30);
        set_bit(bits_array, 50);
        set_bit(bits_array, 70);

        printf("test_bit(bits_array, 50): %d\n", test_bit(bits_array, 50));

        clear_bit(bits_array, 10);
        clear_bit(bits_array, 50);

        printf("test_bit(bits_array, 50): %d\n", test_bit(bits_array, 50));

        return 0;
}
