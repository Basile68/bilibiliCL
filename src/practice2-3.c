#include <stdio.h>

int main()
{
	int input = 0;
	scanf("%d", &input);
	
	int a = 0;
	int b = 0;
	int c = 0;
	
	a = input / 100;
	b = (input % 100) / 10;
	c = input - a*100 - b*10;
	
	int output;
	
	output = c*100 + b*10 + a;
	
	printf("%d",output);
	
	return 0;
}
