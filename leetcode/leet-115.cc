#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution {
public:
    //derive from genius guy
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        //dp[i][j] represent the the number of sub string s[0, i] after delete zero 
        //or one more char is equal to t[0, j]
        //dp[0][j], if the s is empty, there is no way to generate the sub string equal with t
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0)); // int overflow
        //if the string t is empty, the only way to generate the t is delete all char in s
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]){
                    //if equal, there two condition 
                    //s and t skip the a char or s skip char and t do nothing
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }else{
                    //if the char is not equal, check the s sub-string[0, i - 1] 
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
    
    //other solution from csdn
    int numDistinct(string s, string t) {
        int n = t.size();
        vector<unsigned> dp(n + 1, 0);
        dp[0]=1;
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = n; j >= 1; j--)
            {
                if(s[i - 1] == t[j - 1])
                    dp[j]= dp[j] + dp[j - 1];
            }
        }
        return dp[n];
    }
};