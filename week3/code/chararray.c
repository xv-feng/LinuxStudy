
#include "myheader2.h"

int main(void)
{
	char arr[30];
	FILE *fp;
	int write_num;

	printf("arr: %s \n", arr);
	fp = fopen("./test1.txt", "w+"); //可读写方式打开，覆盖原内容
	write_num = fwrite(arr, sizeof(arr), 1, fp);
	printf("write_num : %d", write_num); 

	return 0;
}
