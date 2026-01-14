#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int f = 1;
	int i = 0;
	for ( ; i < n; i++ ) {
		f *= 10;
	}

	int t;
	for ( t = f/10; t < f; t++ ){
		i = n;
		int m;
		int sum = 0;
		int tf = t;
		
		while ( i > 0) {
			m = tf%10;
			tf /= 10;
			i--;
			
				int j = 1;
				int s = 1;
				while ( j <= n) {
					s *= m;
					j++;
				}
				
			sum += s;
			}
			
		if ( sum == t ) {
		printf("%d\n", t);
		}
	}

	return 0;
}

