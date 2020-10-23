
#include "myheader3.h"

int main(int argc, char **argv)
{
	int d1;

	d1 = open("./out.info", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	// 文件描述字0 1 2 分别代表标准输入、输出和错误
	dup2(d1, 1);  //将标准输出重定向到d1 ， 即文件./out.info
	//
	//d1 = dup(STDOUT_FILENO); //将标准输出复制给 d1, 修改了d1 的指向，并不会影响到STDOUT_FILENO；

	printf("Redirect stdout! \n");

	return 0;
}
