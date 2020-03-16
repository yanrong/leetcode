#include <string>
using std::string;
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1, pos;
        int len = s.size();
        if (len <= 1)//a char is palindromic
            return s;
        bool dp[len][len]={false}; //[i][j] represent substring from i to j is palindromic string
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = true; //sub string from index i to i must be palindromic
        }

        for (int i = 0; i < len - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true; //if adjacent two char is palindromic, mark it
                max_len = 2;
                pos = i;
            }
        }
        for(int k = 3; k <= len; k++){ //init span, a and increment to whole length
            for(int i = 0; i <= len - k; i++){
                int j = i + k - 1;
                if(s[i]== s[j] && dp[i+1][j-1]){ //judge from third char, if it is equal and sub string is parlindromic
                    dp[i][j] = true;
                    pos = i;
                    max_len  = k;
                }
            }
        }

    return s.substr(pos, max_len);
    }
};