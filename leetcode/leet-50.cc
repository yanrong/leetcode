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
};
//LeetCode-Solution official
class Solution {
public:
    //solution fastMul in recurese
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
    
    //solution fastMul in iterator
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main(int argc, const char** argv) {
    Solution s;
    double ret = s.myPow1(2, 10);
    std::cout << "ret " << ret <<std::endl;
    return 0;
}