#include <iostream>
#include <string>
#include <vector>
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
    //official solution
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool>> dp(pLen, vector<bool>(sLen, false));

        if(p == s || p == "*") return true;
        if(s.empty() || s.empty()) false;
        //dp[i][j] the sub string before index i in p and the substring before index j in s is matched
        dp[0][0] = true;
        //dp compute
        for(int pIdx = 1; pIdx < pLen; pIdx++){
            //the current character in the patter is '*'
            if(p.at(pIdx - 1) == '*'){
                int sIdx = 1;
                // d[p_idx - 1][s_idx - 1] is a string-pattern match
                // on the previous step, i.e. one character before.
                // Find the first idx in string with the previous math.
                while(!dp[pIdx - 1][sIdx - 1] && (sIdx < sLen)) sIdx++;
                // If (string) matches (pattern),
                // when (string) matches (pattern)* as well
                dp[pIdx][sIdx - 1] = dp[pIdx - 1][sIdx - 1];
                // If (string) matches (pattern),
                // when (string)(whatever_characters) matches (pattern)* as w
                while(sIdx < sLen) dp[pIdx][sIdx++] = true;
            }else if(p.at(pIdx - 1) == '?'){
                for(int sIdx = 1; sIdx < sLen; sIdx++){
                    dp[pIdx][sIdx] = dp[pIdx - 1][sIdx - 1];
                }
            }else{
                for(int sIdx = 1; sIdx < sLen; sIdx++){
                    dp[pIdx][sIdx] = dp[pIdx - 1][sIdx - 1] && p.at(pIdx - 1) == s.at(sIdx - 1);
                }
            }
        }
        return dp[pLen - 1][sLen - 1];
    }

    bool isMatch(string s, string p) {
        int sLen =  s.size(), pLen = p.size();
        int sIdx = 0, pIdx = 0;
        int startIdx = -1, sTmpIdx = -1;

        while(sIdx < sLen){
            //if the pattern character = string chararcter or patter chararcter = '?'
            if(pIdx < pLen && (p.at(pIdx) == '?' || p.at(pIdx) == s.at(sIdx))){
                sIdx++;
                pIdx++;
            }else if(pIdx < pLen && p.at(pIdx) == '*'){
                //if pattern character ='*'
                //check the situation when '*' matches no chararcters
                startIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++;
            }else if(startIdx == -1){
                //If pattern character != string character or pattern is used up
                // and there was no '*' chararcter in patterns
                return false;
            }else{
                //If pattern character != string character or pattern is used up
                // and there was '*' chararcter in patterns before
                //backtrace: check the situation, when '*' matches one more character
                pIdx = startIdx + 1;
                sIdx = sTmpIdx + 1;
                sTmpIdx = sIdx;
            }
        }
        //The remaining characters in the pattern should all be '*' characters
        for(int i = pIdx; i < pLen; i++){
            if(p.at(i) != '*') return false;
        }
        return true;
    }
};