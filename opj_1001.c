#include <stdio.h>
#include <string.h>

int mul(int *res,int k,int len)
{
	int i = 0, c = 0 ;
	for( ; i < len; i++)
	{
		int r = res[i] * k + c;
		res[i] = r % 10;
		c = r / 10;
	}
	while(c)
	{
		res[i++] = c%10;
		c /= 10;
	}
	return i;
}

int main()
{
	char s1[6],r[512];
	int res[512];
	int i, j = 0, n, k, p = 0, len;
	while(scanf("%s%d", s1, &n) != EOF)
	{
		k = 0;
		memset(r,0,sizeof(r));
		memset(res,0,sizeof(res));
		for(i = 0 ; i < strlen(s1); i++)
		{
			if(s1[i] == '.'){p = (strlen(s1) - (i + 1))*n ;continue;}
			k = (s1[i] - '0') + k*10;
			res[j++] = s1[i];
		}
		len = j;
		printf("len=%d  k = %d p = %d\n", len,k,p);
		for( j = 0; j < n-2 ; j++)
		{
			len = mul(res, k, len);printf("len=%d\n", len);
		}
		for(j = 0 ; j < len-1; j++)
			printf("%d",res[j]);

		int kk = 0;
		if(len <= p)
		{
			r[kk++] = '.';
			for(i =0 ; i < p-len; i++)
				r[kk++] = '0';
			for(i = len - 1; i > 0; i-- )
				r[kk++] = res[i];
			r[kk] = '\0';
		}else{
			for(i = len - 1; i >= 0; i--)
			{
				if(i == p ) r[kk++] = '.';
				r[kk++] = res[i];
			}
			r[kk] = '\0';
		}
		
		printf("%s\n",r);
	}
}
