#include <iostream>
#include <climits>
using std::cout;
using std::endl;

class Solution {
public:
    int reverse(int x) {
        long ret = 0 ;

        while(x){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return ret > INT_MAX || ret < INT_MIN ? 0 : ret;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << "\ns " << s.reverse(-6469)<<endl;
    return 0;
}