
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

/*
 * 函数功能：打印错误信息并退出exit(1)
 * 函数参数：char *errmsg , 指向错误信息字符串的字符指针
 * 函数返回值：无
 */
void Err_exit(char *errmsg)
{
	printf("Usage: %s failed! \n", errmsg);
	exit(1);
}


/*
 * 函数功能：获得一个介于最大值和最小值之间的随机数
 * 函数参数：int min 需要随机数的最小值 int max 需要随机数的最大值
 * 函数返回值：介于min 和 max 之间的随机数（包含min 和 max）
 */
int GetRand(int min, int max)
{
	int random_num;  //结果随机数
	
	srand(time(NULL)); // 以Unix纪元至今的秒数设置随机数种子
	random_num = rand()%(max - min + 1) + min; //取min 和 max之间的随机数，包括两端
	
	return random_num;
	
}


