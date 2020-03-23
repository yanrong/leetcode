#include <stdio.h>

int main()
{
	int i;
	float m[13],sum = 0;
	for(i = 0; i < 12; i++)
	{
		scanf("%f",&m[i]);
		sum += m[i];
	}

	printf("$%.2f",sum/12);

}