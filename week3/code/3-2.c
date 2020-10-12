
#include "myheader2.h"

/*
 * 用于证明基于文件流的文件操作方案是对 基于文件描述符的封装
 * 其中FILE 里封装了文件描述符fd，结构体中具体的名字为_fileno
 * */
int main(void)
{
	FILE *fp;

	fp = fopen("./test1.txt", "w"); //w代表只读写，创建文件，删除原内容
	printf("file fd(in FILE) = %d \n", fp->_fileno );
	fclose(fp);
	
	return 0;	
}

