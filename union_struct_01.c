/* Use the property of union to reduce the memory usage of strcuture.
 *
 * Reference: https://www.geeksforgeeks.org/difference-structure-union-c/
 * Reference: https://stackoverflow.com/questions/20752551/working-with-a-union-of-structs-in-c#
 */

#include <stdio.h>
#include <stdlib.h>

#define KEY_NUMBER 6

typedef struct content content_t;

struct content{
	union {
		struct {
			int key_1;
			int key_3;
			int key_5;
			int key_7;
			int key_9;
			int key_11;
		};
		int keys[KEY_NUMBER];
	};
};

void content_handler(int key, content_t * target_content)
{
	if (1 == key) {
		printf("key: %d\n", target_content->key_1);
	} else if (3 == key) {
		printf("key: %d\n", target_content->key_3);
	} else if (5 == key) {
		printf("key: %d\n", target_content->key_5);
	} else if (7 == key) {
		printf("key: %d\n", target_content->key_7);
	} else if (9 == key) {
		printf("key: %d\n", target_content->key_9);
	} else if (11 == key) {
		printf("key: %d\n", target_content->key_11);
	} else {
		printf("There is no matched key.\n");
	}
}

int main()
{
	content_t * content_object = (content_t *) malloc (sizeof(content_t));

	for ( int i = 0; i < KEY_NUMBER; i++)
		content_object->keys[i] = i * 100;

	for (int i = 1; i < 15; i+=2)
		content_handler(i, content_object);

	return 0;
}
