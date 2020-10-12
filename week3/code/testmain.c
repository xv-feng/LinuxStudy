
#include "myheader2.h"

/*
 * 参数含义：
 * args: 执行函数时输入参数的个数
 * char *argv[] ：
 * 	输入参数都是字符串，而这个参数就指向这些参数的字符指针数组
 */
int main(int args, char *argv[])
{
	int i;
	
	for(i = 0; i < args; i++)	
		printf("[%d]: %s \n", i, argv[i]);

	return 0;
}

