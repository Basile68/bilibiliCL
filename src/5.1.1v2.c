#include <stdio.h>

int main()
{
	int n, factor, i;
	i = 0;
	factor = 1;
	
	scanf("%d", &n);
	
	i++;
	
	for ( i=1; i<=n; i++ ) {
		factor *= i ;
	}
	
	printf("%d", factor);
	
	return 0;
}
