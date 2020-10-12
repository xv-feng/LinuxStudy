
#include "myheader2.h"

int main(void)
{
	FILE *fp;
	char buff[80];
	int write_num, i;

	//获取并显示你输入的字符串
	memset(buff, 0, sizeof(buff));  //清空buff
	printf("input a string:");
	fgets(buff, sizeof(buff), stdin);  //fgets 会保留输入的结尾换行符
	buff[strlen(buff) - 1] = '\0' ;  //清除末尾换行符
	printf("The content of the string you input: %s \n", buff);
	printf("The length of the stream: %d  \n", sizeof(buff));
	
	//测试buff里还有无换行符
	for(i = 0; i < sizeof(buff); i++)
	{
		if(buff[i] == '\n')
		{
			printf("\\n exists! \n");
			break;
		}
	}

	//将你输入的字符串写入文件
	fp = fopen("./test1.txt", "w");
	if(fp == NULL)
	{
		perror("fopen error! \n");
	}
	else  //文件打开成功
	{
		// fwrite 每项长度为4  共sizeof(buff) / 4项
		// 函数返回成功写入的项数,成功写入则返回sizeof(buff)/4
		//sizeof把后面的'\0' 也写进文件。没关系，换行符'\n'以及被清掉了
		write_num = fwrite(buff, 4, sizeof(buff)/4, fp);
		printf("fwrite returns : %d \n", write_num);
	}
	fclose(fp);

	return 0;
}
