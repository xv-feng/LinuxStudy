
#include "myheader3.h"

int main(int argc, char **argv)
{
	int n, from, to;
	char buff[10];

	if(argc != 3)  //判断命令行传参是不是三个：文件名，源文件，目的文件
	{
		printf("传入参数个数错误！\n");
		exit(1);
	}
	if((from = open(argv[1], O_RDONLY)) < 0)   //打开源文件失败
	{
		printf("打开源文件失败！\n");
		exit(0);
	}
	//以只写方式打开目的文件，若不存在则新建
	if((to = open(argv[2], O_WRONLY | O_CREAT | O_APPEND)) < 0) //目的文件打开失败
	{
		printf("目的文件打开打开失败！ \n");
		exit(1);
	}

	while((n = read(from, buff, sizeof(buf))) > 0)  //写入文件
		write(to, buf, n);
	close(from);
	close(to);

	return 0;
}
