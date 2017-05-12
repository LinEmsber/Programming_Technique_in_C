/* The example of MACRO: offsetof() */

#include <stdio.h>
#include <stdint.h>

#define offsetof(TYPE, MEMBER) ( (size_t) & ( (TYPE *) 0 ) -> MEMBER )

struct s {
	int32_t member_0;
        int8_t member_1;
        int8_t member_2;
        int16_t member_3;
        int32_t member_4;
};

int main()
{

	/* This will print 0 */
	printf("&( (struct s*) 0 ) -> member_0: %zu\n", offsetof(struct s, member_0) );
	
	/* This will print 4 */
	printf("&( (struct s*) 0 ) -> member_1: %zu\n", offsetof(struct s, member_1) );
	
	/* This will print 5 */
	printf("&( (struct s*) 0 ) -> member_2: %zu\n", offsetof(struct s, member_2) );

	/* This will print 6 */
	// printf("&( (struct s*) 0 ) -> member_3: %zu\n", &( (struct s*) 0 ) -> member_3 );
	printf("&( (struct s*) 0 ) -> member_3: %zu\n", offsetof(struct s, member_3) );
	
	/* This will print 8 */
	// printf("&( (struct s*) 0 ) -> member_3: %zu\n", &( (struct s*) 0 ) -> member_4 );
	printf("&( (struct s*) 0 ) -> member_3: %zu\n", offsetof(struct s, member_4) );

	return 0;
}
