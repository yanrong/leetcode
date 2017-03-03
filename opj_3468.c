#include <stdio.h>

int main()
{
	int n, i, j = 0, arr[1000], max, sum;
	float r[1000];
	while(scanf("%d",&n) != EOF)
	{
		sum = max = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
			if(max < arr[i]) max = arr[i];
		}

		if(sum - max > max)
			r[j++] = sum / 2.0;
		else r[j++] = sum - max;
	}

	for (i = 0; i < j; ++i) printf("%.1f\n", r[i]);
}