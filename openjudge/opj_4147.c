#include <stdio.h>

void move(int n, char from, char to)
{
	printf("%d:%c->%c\n",n,from,to);
}
void hanoi(int n, char from, char by, char to)
{
	if(n == 1)
		move(1,from,to);
	else
	{
		hanoi(n-1, from, to, by);
		move(n, from, to);
		hanoi(n-1,by, from, to);
	}
}

int main()
{
	int n;
	char a,b,c;
	scanf("%d %c %c %c",&n,&a,&b,&c);
	hanoi(n,a,b,c);
}