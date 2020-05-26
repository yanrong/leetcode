#include <stdio.h>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

/**
* ax + by = gcd(a,b)
*/
int ext_gcd(int a, int b, int x, int y)
{
	if(b == 0)
	{
		x = 1; y =0;
		return a;
	}
	int q = ext_gcd(b, a % b, x, y);
	y -= a / b * x;
	return q;
}

/*
*ax + by = gcd(a, b) = d
*/

int ext_gcd2(int a, int b, int x, int y)
{
	if(b == 0)
	{
		x = 1; y =0;
		return a;
	}

	int c = ext_gcd2(b, a % b, x, y);
	int t = x;
	x = y; y = t - a / b * y;
	return c;
}