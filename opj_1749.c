#include <stdio.h>

int main()
{
	int i,j,k,max = 0,n;
	scanf("%d",&n);
	for(i = 0; i<= n; i++){
		for(j = 0; j <= n; j++){
			for(k = 0; k <= n; k++)
			{
				if(!((i+j)%2) && !((k+j)%3) && !((i+j+k)%5))
				{
					if((i+j+k) > max) max = (i+j+k);
				}
			}
		}
	}
	
	printf("%d",max);
	return 0;
}
