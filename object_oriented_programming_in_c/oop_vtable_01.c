/* A virtual method table (VMT) is a mechanism used in a programming language to support
 * dynamic dispatch (or run-time method binding).
 */

#include <stdio.h>

/* typedef */
typedef struct base base_t;
typedef struct child child_t;


/* class definitions */
struct base {
	void (**vtable)();
	int _x;
};

struct child {
	void (**vtable)();

	/* begin base class slice */
	int _x;
	/* end base class slice */

	int _y;
};


/* class method implementations */
void base_to_string(base_t const * obj)
{
	printf("base: (%d)\n", obj->_x);
}

void child_to_string(child_t const * obj)
{
	printf("base: (%d,%d)\n", obj->_x, obj->_y);
}


/* vtable implementation */
enum {
	call_to_string
};

/* pointer to an array of functions */
void (* base_vtable[] )() = { &base_to_string };
void (* child_vtable[] )() = { &child_to_string };


/* virtual method implementation */
void to_string(base_t const * obj)
{
	obj->vtable[call_to_string](obj);
}


int main()
{
	// bast_t base_entry = {base_vtable, 123};
	base_t base_entry;
	base_entry.vtable = base_vtable;
	base_entry._x = 123;

	// child child = {child_Vtable, 456, 789};
	child_t child_entry;
	child_entry.vtable = child_vtable;
	child_entry._x = 456;
	child_entry._y = 789;

	base_t * a = &base_entry;
	base_t * b = (base_t *) &child_entry;

	/* call the virtual methods */
	to_string(a);
	to_string(b);

	return 0;
}
