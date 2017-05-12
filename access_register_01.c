/* A method to access register.
 *
 * References:
 * http://stackoverflow.com/questions/24726251/accessing-sfr-special-function-registers-on-a-32-bit-controller
 */

#include <stdio.h>
#include <stdint.h>

volatile uint32_t* register_addr = 0x80;
#define REG_1 (*register_addr)

// #define DEFINE_SFR(variable_name, address) {( #define (variable_name) (* (volatile uint32_t *) (address) ) )}

int main()
{
        // DEFINE_SFR(REG_1, 0x80);

        printf("address of REG_1: %p\n", REG_1);
        REG_1 = 0xff;
        printf("content of REG_1: %p\n", REG_1);
}
