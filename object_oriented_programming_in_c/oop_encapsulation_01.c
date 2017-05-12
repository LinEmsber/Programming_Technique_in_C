/* An example of object oriented programming in C.
 * An object includes the interges and the operations: add and sum.
 */

#include <stdio.h>
#include <stdlib.h>

/* forward declaration */
typedef struct _object object;
typedef int (*func_t)(object *);

struct _object {
        int a, b;
        func_t add, sub;
};

/* operation function */
static int add_impl(object *self)
{
        return self->a + self->b;
}

static int sub_impl(object *self)
{
        return self->a - self->b;
}

/* Initialize an object, including memory allocation, value intialize,
 * and operations setup.
 */
int init_object(object **self)
{
        *self = malloc( sizeof(object) );
        if (NULL == *self)
                return -1;

        (*self)->a = 0;
        (*self)->b = 0;

        (*self)->add = add_impl;
        (*self)->sub = sub_impl;

        return 0;
}

int main(int argc, char *argv[])
{
        object *o = NULL;
        init_object(&o);

        o->a = 1300;
        o->b = 300;

        printf("add: %d, sub: %d\n", o->add(o), o->sub(o));

        free(o);

        return 0;
}
