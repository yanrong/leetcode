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
    // official solution
    bool isPalindrome(int x) {
        /*the analyse case as belowing
        * if x < 0 , it can't be palindrome
        * if first numver is 0, only 0 is match palindrome
        */
        int ret = 0;
        
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        
        while(x > ret){
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        //if length is odd(center is pivot, skip it), ret / 10 can remove center number
        //if input 12312, finally result x = 12, ret = 123,
        return x == ret || x == ret / 10;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.isPalindrome(12) <<endl;
    return 0;
}