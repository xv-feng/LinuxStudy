
#include "myheader2.h"

int main(void)
{
	FILE *fp;
	int fd;

	fd = open("./test1.txt", O_WRONLY );  //以只读方式打开
	fp = fdopen(fd, "w");  //只写，方式要和open 里的对应
	printf("Are you kidding me ? \n");
	fprintf(fp, "Are uou kidding me ?");
	fclose(fp);

	return 0;
}

