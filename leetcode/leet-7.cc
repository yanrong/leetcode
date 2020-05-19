#include <iostream>
#include <climits>

using std::cout;
using std::endl;

class Solution {
public:
    //original solution
    int reverse(int x) {
        long ret = 0 ;

        while(x){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret > INT_MAX || ret < INT_MIN ? 0 : ret;
    }

    //official solution
    int reverse2(int x){
        int rev = 0;
        while (x != 0){
            int pop = x % 10;
            x /= 10;
            /* max = 2147483647 min = -2147483648
            if rev is too larger to overflow, rev > INTMAX / 10, definite overflow,
            if rev == INTMAX / 10 ( result LSB 2 - 1(100)), pop > 7 rev will be overflow ?
            */
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << "\ns " << s.reverse(-21474836)<<endl;
    return 0;
}