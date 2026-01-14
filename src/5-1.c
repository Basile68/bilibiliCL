/*
分子分母两个变量 l m
比较完大小存储小的变量  min
公约数的变量 i



输入分数 
分子分母比较大小比出小的 

检查有没有公约数
	有公约数就除了再检查有没有公约数
没有公约数就输出 




*/

#include <stdio.h>

int main()
{
	int l, m;
	int min;
	int i = 2;
	
	scanf ("%d/%d", &l, &m);
	
	if ( l <= m ) {
		min = l;
	} else {
		min = m;
	}
	
	while ( i <= min ) {
		if ( l % i == 0 ) {
			if ( m % i == 0) {
				l = l/i;
				m = m/i;
				i = 1;
			}
		}
		i++;
	}
	
	printf("%d/%d", l, m);
	
	return 0;
	
}
