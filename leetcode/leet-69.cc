#include <cmath>
using std::abs;

class Solution {
public:
    //official solution
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
    
    double sqrt2(double x) {
        if (x == 0) return 0;
        double last = 0.0;
        double res = 1.0;
        while (res != last){
            last = res;
            res = (res + x / res) / 2;
        }
        return res;
    }
    //-----------------------------------
    //origin solution binary search 
    int mySqrt(int x) {
        int l, r, m;
        l = 0;
        r = x;
        m = (l + r) / 2;
        if(x == 0 || x == 1) return x;
        
        while ((r - l) > 1){
            if(m * m > x){
                r = m;
            }else{
                l = m;
            }
            m = (l + r) / 2;
        }
        
        return m;
    }

    //official solution
    int mySqrt(int x) {
        if (x < 2) return x;

        double x0 = x;
        double x1 = (x0 + x / x0) / 2.0;
        while (abs(x0 - x1) >= 1) {
            x0 = x1;
            x1 = (x0 + x / x0) / 2.0;
        }

        return (int)x1;
    }
};
