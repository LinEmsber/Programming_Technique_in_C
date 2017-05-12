#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Force a compilation error if condition is true, but also produce a
 * result (of value 0 and type size_t), so the expression can be used
 * e.g. in a structure initializer (or where-ever else comma expressions
 * aren't permitted). */
#define BUILD_BUG_ON(condition) ((void)BUILD_BUG_ON_ZERO(condition))
#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))


typedef struct node {
	int val;
	void * data;
	struct node * next;
}node_t;


int main()
{
	node_t * n;
	n = malloc( sizeof(*n) );
	n->val = 10;

	printf("sizeof(n): %lu\n", sizeof(*n));
	printf("sizeof(n): %lu\n", sizeof(n->val));

	/* It only can be used in compile time value. */
	BUILD_BUG_ON ( (sizeof(*n) != 24) );
	BUILD_BUG_ON ( sizeof(n->val) > sizeof(*n) );

	/* The run time value cannot be detectd, we only can use assert().
	 * BUILD_BUG_ON ( n->val != 10 );
	 */
	assert ( n->val == 10 );

	return 0;
}
