#include <stdio.h>

int main()
{
	int current_time = 0;
	int time_elapse = 0;
	
	printf("请输入起始时间和流逝的时间：");
	scanf("%d %d", &current_time, &time_elapse);
	
	int current_hour = current_time / 100;
	int current_minute = current_time%100;
	int total_current_minute = (current_hour * 60) + current_minute;
	
	int total_arrival_minute = total_current_minute + time_elapse;
	
	int arrival_hour = 	total_arrival_minute / 60;
	int arrival_minute = total_arrival_minute % 60;
	
	int arrival_time = (arrival_hour * 100) + arrival_minute;
	
	printf("arrival time:%d\n", arrival_time);
	
	return 0;
}
