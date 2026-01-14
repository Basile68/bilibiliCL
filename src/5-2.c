/*
储存输入整数的变量x
用来数位数的中间变量t 和 代表有多少位的mask 
代表每位上的数type

输入整数
把数变正
然后倒过来 
提取每个位上的数
通过每个位上的数定位到对应switch-case里的case



*/

#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	if ( x < 0 ) {
		printf ("fu ");
		x = -1 * x;
	}
	
	int t = x;
	int mask = 1;
	
	while ( t > 9 ) {
		t /= 10;
		mask *= 10;
	}
	
	do {
		
		int type = x / mask;
		x %= 10;
		mask /= 10;
		
		switch (type) {
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;				
			case 3:
				printf("san");
				break;				
			case 4:
				printf("si");
				break;				
			case 5:
				printf("wu");
				break;				
			case 6:
				printf("liu");
				break;				
			case 7:
				printf("qi");
				break;				
			case 8:
				printf("ba");
				break;				
			case 9:
				printf("jiu");
				break;											
		}
		
			if ( mask > 0) {
				printf (" ");
			}		
		 
	} while ( mask > 0);
	
	return 0;
}
