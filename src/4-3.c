#include <stdio.h>

int main()
{
	int M, N, max, min, t, sta, sum;
	
	scanf("%d %d", &M, &N);
	
	if ( M > N) {
		max = M;
		min = N;
	} else {
		max = N;
		min = M;
	}
	
	sta = 0;
	sum = 0;
	
	for ( t = min; t <= max; t++) {
		
		int i = 2;
		int isPrime = 1;
		
		for ( ; i < t; i++) {
			if ( t%i == 0) {
				isPrime = 0;
				break;
				} 
			}
			
		if ( isPrime == 1) {
			sta++;
			sum += t;
		}
			
		}
	
	printf("%d %d", sta, sum);
	
	return 0;
}


/* M N 两个变量存储比较大小后 max min 一个变量储存测试值 t 一个变量储存素数个数 sta 一个储存和 sum
 比较大小后确认范围 
 for（）得出一个数，确认它是否是素数，如果是素数 sta++ sum+=t 
 
 确认它是否是素数：
 只要有一个不是1和它本身的数能被它整除，就不是素数，反之则是素数 */
