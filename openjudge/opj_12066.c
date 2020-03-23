#include <stdio.h>
#include <stdlib.h>
typedef struct cow
{
	int s, e, p;
} cow;

static int comp(const void *x, const void *y)
{
	return ( ((cow* )x)->s - ((cow* )y)->s );
}

int main()
{
	cow c[50000];
	int res[50000];
	int i,j,n,k = 0,l;
	scanf("%d",&n);
	for(i = 0; i < n ; i++)
	{
		scanf("%d%d",&(c[i].s),&(c[i].e));
		c[i].p = i+1;
	}
	qsort(c,n,sizeof(cow),comp);
	res[k++] = c[0].p;
	l = 1;
	for(i = 1; i < n; i++)
	{
		int flag = 0;
		for(j = l-1 ; j >= 0; j--)
		{
			if(c[i].s >= c[j].e){
				res[k++] = c[i].p;//j+1;
				c[j].e = c[i].e;
				flag = 1;
				break;
			}
			
		}
		if(!flag){
			l++;
			res[k++] = c[i].p;
		} 
	}

	printf("%d\n",l);
	for(i = 0; i < k; i++)
		printf("%d\n",res[i]);
	return 0;
}