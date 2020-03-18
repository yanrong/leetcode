#include <iostream>
#include <string>
#include <vector>
using namespace std;
//dp[i][j] s[0, i-1] is match with p[0, j-1]
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int l1 = s.size();
        int l2 = p.size();
        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
        dp[0][0] = true;//empty string just match itself
        for(int j = 1; j <= l2; j++){
            dp[0][j] = j > 1 && p[j-1] =='*'&&dp[0][j-2];
        }
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                if(p[j-1] != '*'){
                    dp[i][j] = (s[i-1] == p[j-1]||p[j-1] == '.') && dp[i-1][j-1];
                }else{
                    dp[i][j] = (j > 1 && dp[i][j-2]) || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];//这里i-1相当于递归时的i+1
                }
            }
        }
        return dp[l1][l2];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[m+1][n+1] = {false};
        dp[0][0] = true;
        //is p is empty, only can match s
        for (int i = 1; i <= m; i++)
            dp[i][0] = false;
        //if s is empty, only x* can match it
        for (int j = 1; j <= n; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    //none matched,  if a char before * is matched, and try if more mutiple is matched,
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
                }
                else //dp[i-1][j-1] and s[i-1] == p[j-1],
                {
                    dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }

    bool isMatch(string s, string p) {
        //empty patter only can mathched with empty origin.
        if(p.empty()) return s.empty();

        bool first_match = (!s.empty() && (p.at(0) == s.at(0) || p.at(0) == '.'));
        if(p.size() >= 2 && p.at(1) == '*'){
            return (isMatch(s, p.substr(2)) 
                || first_match && isMatch(s.substr(1), p));
        }else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    string str = "aa", p= "a*";
    string ret = s.isMatch(str, p) ? "true" : "false";
    cout << ret << endl;
    return 0;
}
