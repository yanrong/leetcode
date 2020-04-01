#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        //the substring before index i in s is matched with substring before index j in p
        bool dp[m+1][n+1]={false};
        if (m == 0 && n == 0) return true;
        if (n == 0) return false;
        //empty s and p is matched
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){//is string s is empty, only can match with one or more *
            dp[0][i] = p[i - 1] == '*' && dp[0][i - 1] ;
        }
        
        for(int i = 1; i <= m; i++){
            //dp[i][0] = p[0] == '*' && dp[i-1][0];
            for(int j = 1; j <= n; j++){
                if(p[j - 1] == '*'){
                    // '*' can match a empty or one more sequence, so this is 
                    // '*' match one or more sequence or matched no one discard '*' 
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }else{
                    //else if char at index is matched or the char in index is . in p,
                    // it can be matched any char, and dp[i-1][j-1] is true
                    dp[i][j] = (p[j - 1] == s[i - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};