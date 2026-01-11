#include <stdio.h>

int main()
{
	int height = 0;
	
	printf("请输入您的身高(单位厘米)为:");
	scanf("%d", &height);
	
	int foot = height / 30.48;
	int inch = ((height / 30.48) - foot)*12;
	
	printf("%d %d", foot, inch);
	
	return 0; 
}
