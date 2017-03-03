#include <stdio.h>
#include <string.h>

int main()
{
	char* Haab[]= {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", \
	 "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

	char* Tzolkin_day[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", \
	 "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	int n, nd, ny , i , j = 0;
	char res[1000][30];
	char mm[10];
	scanf("%d",&n);
	for( ;n > 0; n--)
	{	
		memset(mm,0,sizeof(mm));
		scanf("%d.%s%d", &nd, mm, &ny);
		for( i = 0; i < 19 ; i++)
		{
			 if(!strcmp(mm,Haab[i]))
			 	break;
		}
		long hbd = i*20 + nd + 1 + ny*365;
		int tmp = hbd % 260;
		int tzy = tmp ? hbd / 260:hbd / 260 -1;
		int md = tmp % 13 ? tmp % 13 : 13 ;
		int kk = tmp % 20 ? tmp % 20 - 1 : 19;
		sprintf(res[j++],"%d %s %d\n", md, Tzolkin_day[kk], tzy);
	}
	printf("%d\n", j);
	for(i = 0; i < j; i++)
		printf("%s", res[i]);

	return 0;
}