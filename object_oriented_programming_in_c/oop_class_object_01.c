/* An example of object oriented programming in C.
 * It use one type of commom class for two different types of objects.
 */

#include <stdio.h>

// The top-level class.
typedef struct _commom_class
{
	int (*open)(struct _commom_class * self, char * f_spec);
} commom_class_t;

// Function for the TCP 'class'.
static int tcp_init (commom_class_t * tcp)
{
        tcp->open = &tcp_open;
        return 0;
}
static int tcp_open (commom_class_t * tcp, char * f_spec)
{
	printf ("Opening TCP: %s\n", f_spec);
	return 0;
}

// Function for the HTTP 'class'.
static int http_init (commom_class_t * http)
{
        http->open = &http_open;
        return 0;
}
static int http_open (commom_class_t * http, char * f_spec)
{
	printf ("Opening HTTP: %s\n", f_spec);
	return 0;
}

int main (void)
{
	int status;
	commom_class_t common_tcp, common_http;

	// Same 'base' class but initialised to different sub-classes.
	status = tcp_init (&common_tcp);
        if (status != 0)
                printf("tcp_init");
	status = http_init (&common_http);
        if (status != 0)
                printf("http_init");

	// Called in exactly the same manner.
	status = common_tcp.open(&common_tcp, "bigiron.box.com:5000");
        if (status != 0)
                printf("common_tcp.open");
	status = common_http.open(&common_http, "http://www.microsoft.com");
        if (status != 0)
                printf("common_http.open");

	return 0;
}
