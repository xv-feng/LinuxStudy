#include "myhead.h"

void main(void)
{
	int ret;

	printf("2_2 is running! \n");
       	ret = write(1, "Hello World! \n", 14);
	sleep(100);

	exit(0);
}
