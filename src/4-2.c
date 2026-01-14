#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 1;
	int t = 1;
	
	for ( t = 1 ; t <= n; t++ ) {
		
		i = 1;
		
		while ( i < t) {
			printf("%d*%d=%d ", i, t, t*i);
			i++;
		}
		
		printf("%d*%d=%d\n", i, t, t*i);
	
	}
	
	return 0;
}
