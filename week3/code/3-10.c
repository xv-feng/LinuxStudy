
#include "myheader2.h"

int main(void)
{
	FILE *fp;
	char buf[80];

	memset(buf, 0, sizeof(buf));
	fp = fopen("./test1.txt", "a");
       	//以只写的形式打开，在原文件末尾追加（若不存在则新建）
	fputs("I love haohao~", fp);
	fp = freopen("./test1.txt", "a+", fp ); 
	//以可读写的形式打开，在原文件末尾追加（若不存在则新建）
	fgets(buf, sizeof(buf), fp); //从fp中读取最多sizeof(buf)个字符到buf
	//字符读取会在一个EOF或者是换行结束（保存换行符‘\n’）
	printf("The content in the file: %s \n", buf);
	fclose(fp);

	return 0;
}
