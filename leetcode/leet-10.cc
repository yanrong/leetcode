#include <iostream>
#include <string>
#include <vector>
using namespace std;
//dp[i][j]表示s [0, i-1]与p[0, j-1]是否匹配
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int l1 = s.size();
        int l2 = p.size();
        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
        dp[0][0] = true;//只有空串才能匹配空串
        for(int j=1;j<=l2;j++){
            dp[0][j] = j>1 && p[j-1]=='*'&&dp[0][j-2];
        }
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(p[j-1]!='*'){
                    dp[i][j] = (s[i-1]==p[j-1]||p[j-1]=='.') && dp[i-1][j-1];
                }else{
                    dp[i][j] = (j>1&&dp[i][j-2]) || (s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j];//这里i-1相当于递归时的i+1
                }
            }
        }
        return dp[l1][l2];
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(),n = p.length();
        bool dp[m+1][n+1] = {false};
        dp[0][0] = true;
        //初始化第0行,除了[0][0]全为false，因为空串p只能匹配空串，其他都无能匹配
        for (int i = 1; i <= m; i++)
            dp[i][0] = false;
        //初始化第0列，只有X*能匹配空串
        for (int j = 1; j <= n; j++)
            dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
        
        for (int i = 1; i <= m; i++)
        {
           for (int j = 1; j <= n; j++)
           {
               if (p[j - 1] == '*')
               {
                   dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
               }
               else //只有当前字符完全匹配，才能传递dp[i-1][j-1] 值
               {
                   dp[i][j] = (p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
               }
           }
        }
        
        return dp[m][n];
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
