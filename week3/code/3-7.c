
#include "myheader2.h"

int main(int args, char *argv[])
{
	FILE *fp;
//	char buff[80];
	int write_num;
	int i ;

	//获取并显示你输入的字符串
//	memset(buff, 0, sizeof(buff));  //清空buff
//	printf("input a string:");
//	fgets(buff, sizeof(buff)-1, stdin);
//	printf("The content of the string you input: %s \n", buff);
//	printf("The length of the stream: %d  \n", sizeof(buff));	
	
	for(i = 0; i < args; i++)
	{
		printf("The strings you've input: \n");
		printf("[%d]: %s \n", i, argv[i]);
	}

	//将你输入的字符串写入文件
	fp = fopen("./test1.txt", "w");
	if(fp == NULL)
	{
		perror("fopen error! \n");
	}
	else  //文件打开成功
	{
		//write_num = fwrite(buff, 1, sizeof(buff), fp);
//		write
		for(i = 0; i < args; i++)
		{
			//write_num = fwrite(argv[i], 1, strlen(argv[i]), fp);
			write_num = fprintf(fp, "%s", argv[i]);
			printf("[%d] :fwrite returns : %d \n", i, write_num);
		}
	}
	fclose(fp);

	return 0;
}
