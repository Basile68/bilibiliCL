#include <stdio.h>

int main()
{
	int height = 0;
	
	printf("请输入您的身高（单位：厘米）：");
	scanf("%d", &height);
	
	double total_height = height / 30.48;
	
	int foot = total_height;
	int inch = (total_height - foot)*12;
	
	printf("%d %d", foot, inch);
	
	return 0;
}
