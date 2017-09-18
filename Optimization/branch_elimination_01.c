#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

int foo(int x)
{
        int x1 = 10, x2 = 15, x3 = 20, x4 = 25;
        int a = 10000, a0 = 10000, a1 = 10100, a2 = 10200, a3 = 10300, a4 = 10400;

        if ( x < x1 )
                a = a0;
        else if ( x < x2 )
                a = a1;
        else if ( x < x3 )
                a = a2;
        else if ( x < x4 )
                a = a3;
        else
                a = a4;

        return a;
}

int foo_optimization(int x)
{
        int x1 = 10, x2 = 15, x3 = 20, x4 = 25;
        int a = 10000, a0 = 10000, a1 = 10100, a2 = 10200, a3 = 10300, a4 = 10400;

        uint32_t x_lt_x1  = (uint32_t)((int32_t)(x - x1) >> 31);
        printf("x_lt_x1: %d\n", x_lt_x1);
        uint32_t x_lt_x2  = (uint32_t)((int32_t)(x - x2) >> 31);
        printf("x_lt_x2: %d\n", x_lt_x2);
        uint32_t x_lt_x3  = (uint32_t)((int32_t)(x - x3) >> 31);
        printf("x_lt_x3: %d\n", x_lt_x3);
        uint32_t x_lt_x4  = (uint32_t)((int32_t)(x - x4) >> 31);
        printf("x_lt_x4: %d\n", x_lt_x4);

        uint32_t result_0 = (x_lt_x4 & a3 ) | (~x_lt_x4 & a4);
        printf("(x_lt_x4 & a3 ): %d, (~x_lt_x4 & a4): %d, (x_lt_x4 & a3 ) | (~x_lt_x4 & a4): %d\n", (x_lt_x4 & a3 ), (~x_lt_x4 & a4), result_0);

        uint32_t result_1 = (x_lt_x3 & a2 ) | (~x_lt_x3 & result_0);
        printf("(x_lt_x3 & a2 ): %d, (~x_lt_x3 & result_0): %d, (x_lt_x3 & a2 ) | (~x_lt_x3 & result_0): %d\n", (x_lt_x3 & a2 ), (~x_lt_x3 & result_0), result_1);

        uint32_t result_2 = (x_lt_x2 & a1 ) | (~x_lt_x2 & result_1);
        printf("(x_lt_x2 & a1 ): %d, (~x_lt_x2 & result_1): %d, (x_lt_x2 & a1 ) | (~x_lt_x2 & result_1): %d\n", (x_lt_x2 & a1 ), (~x_lt_x2 & result_1), result_2);

        uint32_t result   = (x_lt_x1 & a0 ) | (~x_lt_x1 & result_2);
        printf("(x_lt_x1 & a0 ): %d, (~x_lt_x1 & result_2): %d, (x_lt_x1 & a0 ) | (~x_lt_x1 & result_2): %d\n", (x_lt_x1 & a0 ), (~x_lt_x1 & result_2), result);

        return result;
}

int main()
{
        // assert( foo(7) == foo_optimization(7) );
        // printf("foo(7): %d\n", foo(7));
        // printf("foo_optimization(7): %d\n", foo_optimization(7));

        assert( foo(12) == foo_optimization(12) );
        // printf("foo(12): %d\n", foo(12));
        // printf("foo_optimization(12): %d\n", foo_optimization(12));

        // assert( foo(17) == foo_optimization(17) );
        // printf("foo(17): %d\n", foo(17));
        // printf("foo_optimization(17): %d\n", foo_optimization(17));
        //
        // assert( foo(22) == foo_optimization(22) );
        // printf("foo(22): %d\n", foo(22));
        // printf("foo_optimization(22): %d\n", foo_optimization(22));

        return 0;
}
