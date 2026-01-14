/*需要一个A变量，BCD变量；还需要一个计算次数的变量；
输出一个，加一个空格，输出次数足够多的时候不加空格；
*/

#include <stdio.h>

int main()
{
	int A, B, C;
	int i = 0;
	int z;
	
	scanf("%d", &z);
	
	for (A = z; A <= z+3; A++){
		for ( B = z; B <= z + 3; B++) {
			for ( C = z; C <= z + 3; C++) {
				if ( A != B){
					if ( B != C) {
						if ( A != C){
							printf("%d", A*100+B*10+C);
							i++;
							if ( i == 6) {
								printf("\n");
								i = 0;
							} else {
								printf(" ");
							}
						}

					}
				}

			}
		}	
	}

	return 0;
 } 
 
