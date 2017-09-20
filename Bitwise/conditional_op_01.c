#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int conditional_op( int a, int x, int y )
{
    return (a >= 0 ? x : y);
};

int conditional_op_bitwise( int a, int x, int y )
{
    int mask = a >> 31;
    return (x & (~mask)) + (y & mask);
};

int main()
{
        printf("conditional_op_bitwise(1, 100, -100): %d\n", conditional_op_bitwise(1, 100, -100));
        printf("conditional_op_bitwise(-1, 100, -100): %d\n", conditional_op_bitwise(-1, 100, -100));
        printf("conditional_op_bitwise(0, 100, -100): %d\n", conditional_op_bitwise(1, 100, -100));

        return 0;
}
