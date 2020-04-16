#include <cmath>
using std::abs;

class Solution {
public:
//----------solution from csdn---------------------
    double mySqrt(double x) {
        double l, r, m, E = 0.00001;
        l = 0;
        r = x;
        m = (l + r) / 2;
        if(x == 0 || x == 1) return x;
        
        while ((r - l) > E){
            if(m * m > x){
                r = m;
            }else{
                l = m;
            }
            m = (l + r) / 2;
        }
        
        return m;
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

    //newton sqrt algorithm
    //f(x) = x^2 - n = 0
    int mySqrt(int x) {
        // int, overtime in case 8
        double ret, last;
        if(x <= 1) return x;
        last = 0; ret = 1;
        while(ret != last){
            last = ret;
            ret = (ret + x / ret) / 2;
        }
        return ret;
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
