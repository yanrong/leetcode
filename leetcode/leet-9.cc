#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string tmp;
        int len, i;
        bool sign = x > 0 ? true : false;

        if(sign){
            while(x){
                tmp += x % 10 + '0';
                x /= 10;
            }
        }else{
             while(x){
                tmp += (0 - (x % -10)) + '0';
                x /= 10;
            }
            tmp += '-';
        }

        len = tmp.length();
        for(i = 0; i < len / 2; i++){
            if(tmp[i] == tmp[len - 1 - i]) continue;
            else break;
        }

        if( i != len / 2) return false;
        return true;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.isPalindrome(12) <<endl;
    return 0;
}