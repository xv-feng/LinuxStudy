
#include "myheader3.h"

int main(void)
{
	FILE *fp;
	int fd;

	fp = fopen("./myheader3.h", "r");
	fd = fileno(fp);
	// fd = fp->_fileno;
	printf("fd = %d  \n", fd);

	return 0;
}
