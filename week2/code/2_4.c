#include "myhead.h"

int main(void)
{
	int count = 0;
	
	while(1)
	{
		char fileName[64];
		snprintf(fileName, sizeof(fileName), "%d.txt", count);
		creat(fileName, 0664);
		count++;
		//sleep(1);  // creat a new file every second
	}

	return 0;
}
