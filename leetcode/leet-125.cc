#include <string>
using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n == 0) return true;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                s[j++] = tolower(s[i]);
            }
            if(isdigit(s[i])){
                s[j++] = s[i];
            }
        }
        j--;
        for(int i = 0; i <= j; ){
            if(s[i] != s[j] ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};