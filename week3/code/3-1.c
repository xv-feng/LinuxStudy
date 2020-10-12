#include "myheader2.h"

int main(void)
{
	int fd;

	fd = open("./test1.txt", O_CREAT, 0664);
	printf("file fd = %d \n", fd);
	close(fd);

	return 0;
}

