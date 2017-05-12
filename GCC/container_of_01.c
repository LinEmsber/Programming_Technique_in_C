/* An example of macro: container_of() usage */

#include <stdlib.h>
#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                          \
	const typeof ( ((type *)0)->member ) *__mptr = (ptr);       \
	(type *) ( (char *)__mptr - offsetof(type, member) ); })


/* linked list head */
struct list_head {
	struct list_head *next;
	struct list_head *prev;
};

/* function to init list head */
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}


/* demo structure */
struct car {

	unsigned long length;
	unsigned long width;
	char is_nice;

	struct list_head list;
};


int main()
{
	/* create struct car */
	struct car *red_car = malloc(sizeof(struct car));

	/* init struct car */
	red_car->length = 4;
	red_car->width = 2;
	red_car->is_nice = 1;

	/* init list head */
	INIT_LIST_HEAD( &red_car->list );

	/* try to obtain the pointer to car struct: red_car from one of the member of the struct car. */
	struct car *x_car = container_of( &red_car->list, struct car, list );

	if (red_car == x_car){
		printf("It works, no error.\n");

	}else{
		printf("ERROR.\n");
	}

	free(red_car);

	return 0;
}
