/*
变量a和n
总和sum
数列中的某个数t
第i个数 
位数s 

输入两个变量
计算第一个值
加到sum 
计算第二个值再加上第一个值
	计算第二个值是用a*10+a
	再计算第三个值a*100+1*10+a
加到sum 
再计算第n个值
加到sum 
结束 

*/

#include <stdio.h>

int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	
	int sum = 0;
	int t = 0;
	int i = 1;
	int s = 1;
	
	while ( i <= n ) {
		t = a * s + t;
		sum += t;
		i++;
		s *= 10;
	}
	
	printf ("%d", sum);
	
	return 0;
}
