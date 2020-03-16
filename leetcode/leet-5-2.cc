#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return s;
        int maxlen = 0, left = 0, right = 0, substr_left, substr_right, substr_len;
        string max_sub_string = "";
        for(int i = 1; i<len; ++i){
            left = i -1 ;
            right = i;
            // even Palindrome  eg. "abba"
            while(left >=0 && right < len && s[left]==s[right]){
                --left;
                ++right;
            }
            substr_left = left + 1;
            substr_right = right - 1;
            substr_len = substr_right -substr_left + 1 ;
            if(substr_len > maxlen){
                max_sub_string = s.substr(substr_left, substr_len);
                maxlen = substr_len;
            }

            // odd Palindrome eg. "abcba"
            left = i - 1;
            right = i + 1;
            while(left >=0 && right < len && s[left] == s[right]){
                --left;
                ++right;
            }
            substr_left = left + 1;
            substr_right = right - 1;
            substr_len = substr_right -substr_left + 1 ;
            if(substr_len > maxlen){
                max_sub_string = s.substr(substr_left, substr_len);
                maxlen = substr_len;
            }   
        }
        return max_sub_string;
    }

    string longestPalindrome2(string s) {
        if(s.size() <= 1) return s;

        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len - 1) /2;
                end = i + len / 2;
            }
        }
        //s.substr(start, end); // cpp substr - get string from start with len end 
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right){
        int l = left, r = right;
        while( l >= 0 && r < s.size() && s[l] == s[r]){
            l--; r++;
        }

        return r - l - 1;
    }
};

int main(int argc, const char** argv) {
    string s("scfcacgd");
    Solution solution;
    string c = solution.longestPalindrome(s);
    cout<<"S = " << c << endl;
    return 0;
}