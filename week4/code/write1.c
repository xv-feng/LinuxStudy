
#include "myheader3.h"

int main(void)
{
	int n, i, fd;
	char buf;

	fd = open("./test.dat", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	for(i = 0; i < 2; i++)
	{
		//srand(time(0));
		//n = rand() % 26;  //取0 - 25 的随机数
		n = GetRand(0, 25);   //调用自己封装的随机数函数，0-25，包括两端
		buf = (char)('a' + n);
		printf("write1: %c \n", buf); 
		write(fd, &buf, 1);
		lseek(fd, 10, SEEK_SET);
		sleep(15);  //休眠 15 秒
	}

	close(fd);
	return 0;
}
