/*
储存随机数rand和猜测的最大次数n的两个变量

用户输入的变量num 记录用户猜测次数的变量i

输入随机量和猜测次数；

{
用户输入 猜测次数+1 

进行对比如果是负数，game over 

进行对比 1. 对的话
 			1次bingo
			 3次 lucky you
			 3到n次之间 good guess
			  
         2. 不对的话进行对比
		 	大了 too big
			 小了 too small 
}
如果大于n次了 game over 




*/ 

#include <stdio.h>

int main()
{
	int rand = 58;
	int n = 4;
	
	int num = 0;
	int i = 0;
	
	while ( i <= n ) {
		printf ( "请输入：");
		scanf ("%d", &num);
		
		if ( num < 0) {
			printf ("Game Over");
			break;
		}
		
		i++;
		
		if ( num == rand) {
			if ( i == 1) {
				printf ("Bingo!");
				break;
			}
			if ( i <= 3 ) {
				printf ("Lucky You!");
				break;
			}
			if ( i <= n ) {
				printf("Good Guess!");
				break;
			}
		}
		
	}
	
	if ( i > n ) {
		printf ("Game Over");
	}
	
	return 0;
}
