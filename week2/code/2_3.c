#include "myhead.h"

void main(void)
{
	int ret;
	char buf[101];
	FILE *fp;
       	//string  buffer 100characters max.The last one is reserved to
	// store '\0' 


	printf("process:%d, 2_3 is running! \n", getpid());
       	ret = write(1, "Hello World! \n", 14);
	sleep(3);

	printf("Please input a string(length <= 100):");
	fgets(buf, sizeof(buf)-1, stdin);
	fp = fopen("./string.txt", "w+");
	fputs(buf, fp);
	fclose(fp);

	exit(0);
}
