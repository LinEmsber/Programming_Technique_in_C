/* Use integer array to represent a sequence of bits array.
 * It can be used for dynamic programming to record the boolean results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  set_bit(int * A,  int k)
{
        int index = k / 32;
        int pos = k % 32;
        unsigned int flag = 1;

        flag = flag << pos;
        A[index] = A[index] | flag;
}

void  clear_bit(int * A,  int k)
{
        int index = k / 32;
        int pos = k % 32;
        unsigned int flag = 1;

        flag = flag << pos;
        A[index] = A[index] &~ (flag);
}

int test_bit(int * A,  int k)
{
        int index = k / 32;
        int pos = k % 32;
        unsigned int flag = 1;

        flag = flag << pos;

        return (A[index] & flag ) != 0;
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
