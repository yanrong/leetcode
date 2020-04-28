#include <string>
#include <vector>
#include <algorithm>
using std::sort;
using std::string;
using std::vector;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if(str1 == str2) return true;
        /***
         * from i to s1 size, cut the s1 ans s2 into two part
         * s1l s1r and s2l s2r, in normal case, if the  s1l == s2l and s1r == s2r, in this situation
         * matched. otherwise if the s1l == s1r and s1r == s2l, this cast the s1 left tree
         * is equal to s2 right tree and s1 right tree is equal s2 left tree
         * **/
        for(int i = 1; i < s1.size(); i++){
            //split at posiont i s1 left part ------ s2 left part
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) 
                && isScramble(s1.substr(i), s2.substr(i))){ // s1 right part ----- s2 right part
                    return true;
                }
            //sl left part ----- s2 right part
            if(isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) 
                && isScramble(s1.substr(i), s2.substr(0, s2.size() - i))){ //s1 right part and s2 left part
                    return true;
                }
        }
        return false;
    }


    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int n = s1.size();
        //the substring s1 start [i] with length n is a scramble of s2 start at [j] with length n
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n, vector<int>(n + 1, 0)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for(int len = 2; len <= n; len++){//len from 2 to whole string size
            for(int i = 0; i <= n - len; i++){
                for(int j = 0; j <= n - len; j++){
                    for(int k = 1; k < len; k++){
                        /**split to two part in postion K
                        **if the sub string range from s1[i, i + k) sw[j, j + k) is scramble
                        **the s1[i + k, len - k] s2[j + k, len -k] is cramble then return true 
                        **else if s1[i, i + k] s2[j + len - k, k](j + len - k + k = k) is scramble
                        ** and s2[0, j] s1[i + k, len -k] is scarmble, return true 
                        **/
                        if((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                        (dp[i + k][j][len - k] && dp[i][j + len - k][k])){
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        //return from [0, n] is scramble
        return dp[0][0][n];
    }
};