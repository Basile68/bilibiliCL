#include <stdio.h>

int main()
{
	int n, factor, i;
	i = 0;
	factor = 1;
	
	scanf("%d", &n);
	
	i++;
	
	while (i <= n) {
		factor = factor * i;
		i++;
	}
	
	printf("%d", factor);
	
	return 0;
}
