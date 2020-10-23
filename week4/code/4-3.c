
#include "myheader3.h"

char buf1[] = "abcdefghij";
char buf2[] = "0123456789";

int main(void)
{
	int fd;

	if((fd = open("file.hole.2", O_WRONLY | O_CREAT, 0644)) < 0)
		Err_exit("Create error!");
	if((write(fd, buf1, 10)) != 10)  //将abcd字符串写入文件
		Err_exit("Write error!");
	if((lseek(fd, 40, SEEK_SET)) == -1)  //移动文件指针而不进行写入 并不会修改原来硬盘中的文件
		Err_exit("Lseek error!");
	
	if((write(fd, buf2, 10)) != 10)   //通过lseek 移动文件指针后再追加写入 0123456789
	{
		Err_exit("Write Error!");
	}
	 

	return 0;
}
