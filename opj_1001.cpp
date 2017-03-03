#include <stdio.h>
#include <string.h>

int mul(int a[], int n,int len)
{
    int i;
    int c = 0; 
    for (i = 0; i < len; i++)
    {
        int tmp = a[i]*n + c;
        a[i] = tmp % 10;
        c = tmp / 10;      
    }
    while (c)
    {
        a[i++] = c % 10;
        c /= 10;
    }
    return i;
}

int main(int argc, char* argv[])
{
    int n , len ,p[512] = {0}; // power n
    char s[6]; 
    while (scanf("%s %d", s, &n) != EOF)
    {
        int pos=0, i=0, num=0, j=0;
        for (i=0; i<strlen(s); i++) 
        {
            if (s[i] == '.'){
                pos = (strlen(s) - 1 - i) * n; 
            }else{
                p[j++] = s[i] - 48;
            }       
        }
        len = j;
        for (i = 0; i < n; i++)
        {
            len = mul(p, num, len);
        }
        j = 0;
        if (len <= pos) 
        {
            printf(".");
            for (i=0; i<pos-len; i++)
            {
                printf("0"); 
            }
            for (i=len-1; i>=0; i--)
            {
                printf("%d", p[i]);
            }
        }   
        else
        {
            while (p[j]==0 && j<pos){j++;}
            for (i=len-1; i>=j; i--)
            {
                if (i+1 == pos) 
                {
                    printf(".");
                }
                printf("%d", p[i]);
            }
        }
        printf("\n");
    }
}
