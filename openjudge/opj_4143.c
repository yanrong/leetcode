#include <stdio.h>
#include <stdlib.h>
/**
* openjudge bailian Accepted at Nov 19 2016 ,BIG SURPRISE!!!
*
*/
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
	int n,sum;
	int i,p = 0;
	int arr[100000];
	int s1 = 1000001, s2 = 1000001;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
		p++;
	}
	scanf("%d",&sum);
	qsort(arr,p,sizeof(int),compare);
	for(i = 0; i < p -1 ;i++)
	{
		int mins = sum - arr[i];
		if(bsearch(&mins, arr + (i+1), p - (i + 1), sizeof(int), compare))
		{
			if(arr[i] < s1 /*&& mins < s2*/){
				s1= arr[i]; s2 = mins;
			}
		}
	}
	if(s1 == 1000001 && s2 == 1000001)
		printf("No");
	else
		printf("%d %d",s1,s2);
	
	return 0;
}