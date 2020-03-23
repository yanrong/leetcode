#include <stdio.h>
#include <stdlib.h>

struct  kk
{
	int id, re;
};

int comp(struct kk c1, struct kk c2)
{
	return c1.re - c2.re;
}

int reverse(char *c, int m)
{
	int i, j, r = 0;
	for( i = 0; i < m; i++)
	{
		for (j = i+1; j < m; ++j)
		{
			if(c[i] > c[j]) r++;
		}
	}
	return r;
}

int main()
{
	int i , j, n, m;
	char s[50][100];
	struct kk ss[50];
	scanf("%d%d",&m,&n);
	for(i = 0; i < n ; i++)
	{
		for( j = 0 ; j < m ; j++)
			scanf("%c",&s[i][j]);
	}
	for(i = 0; i < n ; i++)
	{
		ss[i].id = i;
		ss[i].re = reverse(s[i],m);
	}

	qsort(ss, n, sizeof(struct kk), comp);

	return 0;
}