#include <stdio.h>

int main()
{
	int hour1,minute1;
	int hour2,minute2;

	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	printf("时间差是%d时%d分", hour1-hour2, minute1-minute2);
	
	return 0;
}
