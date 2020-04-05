#include<climits>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        
        for(int i = 0; i < N; i++){
            ret *= x;
        }
        
        return ret;
    }
    
    double fastPow(double x, long long n){
        double temp;
        if(n == 0) return 1;
        temp = fastPow(x , n / 2);
        if(n % 2){
            // if is odd n / 2 will discard 1, so multiply itself
            return temp * temp * x;
        }else{
            //even is prefect divide by 2
            return temp * temp;
        }
    }

    double myPow1(double x, int n) {
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    /**
    * x^n = x^a + x^b so n = a + b + c ....
    * n binary bit show 01010... ,  n = a1 * 2^i1 + a2 * 2^i2....
    **/
    double myPow(double x, int n) {
        long long N = n;
        double ret = 1, tmp;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        tmp = x;
        for(long long i = N; i ; i /= 2){ // each time discard 1bit LSB 
            if((i % 2) == 1){ //check the bit of LSB is 1 or 2
                ret *= tmp; //just multiply x ---- x^(2^(i + 1))
            }
            tmp *= tmp; // x^(2^1) ------ x^(2^i)
        }
    }
    
    //other solution
    double myPow(double x, int n) {
        long long  t;
        double ans(1.0); // initialize

        if (n < 0) x = 1/x;
        t = (long long)(std::labs(n));
        while (t){
            if (t & 1) ans *= x; // 假如低位为1,则乘上x
            x *= x; // x自乘
            t = t >> 1; // 右移一位
        }

        return ans;
    }

};

int main(int argc, const char** argv) {
    Solution s;
    double ret = s.myPow1(2, 10);
    std::cout << "ret " << ret <<std::endl;
    return 0;
}