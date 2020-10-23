
#include "myheader3.h"

int main(void)
{
	int d1, d2;
	char buf[5];

	memset(buf, 0, 5); //用'\0'填充字符数组， 其初始状况下是乱码
	d1 = open("file.hole", O_RDONLY);
	d2 = open("file.hole", O_RDONLY);
	printf("d1、d2 为打开同一文件返回的文件描述符：\n");
	printf("d1 = %d  , d2 = %d  \n", d1, d2);  

	lseek(d1, 5, SEEK_SET); //将d1的文件指针从开头移动5位
	read(d2, buf, 4);   //从d2 读4位到buf 再printf显示
	printf("buf: %s \n", buf);

	return 0;
}
