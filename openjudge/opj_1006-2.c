#include <stdio.h>
 
int main(void)
{
    int p,e,i,d;
    int time=1;
    while(cin>>p>>e>>i>>d)
    {
        if(p==-1 && e==-1 && i==-1 && d==-1)
            break;
 
        int lcm=21252;  // lcm(23,28,33)
        int n=(5544*p+14421*e+1288*i-d+21252)%21252;
        if(n==0)
            n=21252;
        cout<<"Case "<<time++<<": the next triple peak occurs in "<<n<<" days."<<endl;
    }
    return 0;
}