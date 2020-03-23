#include <stdio.h>

int cards(float s)
{
	int i,c=0;
	for(i = 2; ;i++)
	{
		s -= 1.0/i;
		if(s <= 0.00){
			c++; break;
		}
		c++;
	}
	return c;
}

int main()
{
	float h;
	int r[10000],i=0,j;
	while(scanf("%f",&h))
	{
		if(h == 0.00) break;
		r[i++]=cards(h);
	}
	for(j = 0; j < i; j++)
		printf("%d card(s)\n",r[j]);
	return 0;
}