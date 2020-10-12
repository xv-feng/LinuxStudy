
#include "myheader2.h"

int main(void)
{
	FILE *fp;
	char buff[80];
	int write_num;

	//获取并显示你输入的字符串
	memset(buff, '\0', sizeof(buff));  //清空buff, 即为字符数组的每个字符赋值'\0',
	// 0 便是'\0'的ascii码，而默认本来是不确定的乱码。
	printf("input a string:");
	fgets(buff, sizeof(buff)-1, stdin);
	printf("The content of the string you input: %s \n", buff);
	printf("The length of the stream: %d  \n", sizeof(buff));
	
	//将你输入的字符串写入文件
	fp = fopen("./test1.txt", "w");
	if(fp == NULL)
	{
		perror("fopen error! \n");
	}
	else  //文件打开成功
	{
		// fwrite 每项长度为1 共strlen(buff)项
		// 函数返回成功写入的项数
		write_num = fwrite(buff, 1, strlen(buff), fp);
		printf("fwrite returns : %d \n", write_num);
	}
	fclose(fp);

	return 0;
}
