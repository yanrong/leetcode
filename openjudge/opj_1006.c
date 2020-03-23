#include <stdio.h>  

void ext_Euclid(int a, int b, int &x, int &y)
{  
    if(b == 0)  
    {  
        x = 1;  
        y = 0;  
        return ;  
    }  
    ext_Euclid(b, a % b, x, y);  
    int tmp = x;
    x = y;  
    y = tmp - (a / b) * y;  
}  
  
int CRT(int a[],int m[],int n)  
{  
    int M = 1, i;  
    int ans = 0;  
    for(i = 0; i < n; i++)  
        M *= m[i];  
    for(i = 0; i < n; i++)  
    {  
        int x, y;  
        int Mi = M / m[i];  
        ext_Euclid(Mi, m[i], x, y);  
        ans = (ans + Mi * x * a[i]) % M;  
    }  
    if(ans < 0) ans += M;  
    return ans;  
}  
  
int main()  
{  
    int i=0,j,d; 
    int a[3], m[3]={23, 28, 33},res[1000];  
    while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d))  
    {  
        if(a[0] == -1 && a[1] == -1 && a[2] == -1 && d == -1)  
            break;  
        int ans = CRT(a, m, 3);  
        if(ans <= d)  
            ans += 21252;
        res[i++] = ans - d;
        
    }  
    for(j = 0; j < i; j++)
        printf("Case %d: the next triple peak occurs in %d days.\n",j+1,res[j]);

    return 0;  
}  