/*
2 1   1
3 2   2
5 3   3
8 5   4

分子一个变量 l  分母一个变量 m 总和一个变量sum 第几项一个变量n 加几次一个变量 i
分子中间量一个变量j 分母中间量一个变量 k

如果第3项
就要加3次 

把第一个分数加进总和
算出第二个数的分子和分母
	分子是分子和分母的和
	分母是前一项的分子 
i++
*/

#include <stdio.h>

int main()
{
	int l = 2;
	int m = 1;
	
	double sum = 0.0;
	int i = 0;
	int j, k;
	
	int n;
	scanf("%d", &n);
	
	while ( i < n ) {
		sum += 1.0*l/m;
		j = l;
		k = m;
		l = j + k;
		m = j;
		i++;
	}
	
	
	printf ("%.2f", sum);
	
	return 0;
}
