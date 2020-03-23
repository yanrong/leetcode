#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
  	int n, i, j, res[10000];
  	float d[2], r0, r;
  	scanf("%d",&n);
  	for(i = 0; i < n; i++)
  	{
  		scanf("%f%f",&d[0],&d[1]);
      r0 = 0;
  		float dis = sqrt(d[0]*d[0] + d[1]*d[1]);
  		for(j = 1; ; j++)
  		{
  			r = sqrt(2*50.0/PI + r0*r0);
  			r0 = r;
  			if(r >= dis){
  				res[i] = j;
  				break;
  			}
  		}
  	}

    for(j = 0; j < n; j++)
    {
      printf("Property %d: This property will begin eroding in year %d.\n",j+1,res[j]);
    }
    printf("END OF OUTPUT.\n");
  	return 0;
}