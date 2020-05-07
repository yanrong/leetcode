#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    //official solution 1 CPP answer error
    bool isInterleave(string s1, string s2, string s3) {
        return isSubInterleave(s1, 0, s2, 0, "", s3);
    }
    bool isSubInterleave(string s1, int i, string s2, int j, string ret, string s3){
        if(ret == s3 &&  i == s1.size() && j == s2.size()){
            return true;
        }
        
        bool ans = false;
        if(i < s1.length()){
            ans = ans || isSubInterleave(s1, i + 1, s2, j, ret += s1.at(i), s3);
        }
        if(j < s2.size()){
            ans = ans || isSubInterleave(s1, i, s2, j + 1, ret += s2.at(j), s3);
        }
        
        return ans;
    }
    
    /** Solution 2
    ** dp from leetcode official origin
    ** main idea is dp[i][j] represent the sub string range in [0 , i) in s1 and [0, j) in s2
    ** can combine a valid prefix of s3, total number of char is i + j - 1
    **/
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()){
            return false;
        }
        
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        for(int i = 0; i <= s1.length(); i++){
            for(int j = 0; j <= s2.length(); j++){
                if(j == 0 && i == 0){//empty string return true
                    dp[i][j] = true;
                }else if(i == 0){//just compare the s2 with s2
                    dp[i][j] = dp[i][j - 1] && s2.at(j - 1) == s3.at(i + j - 1);
                }else if(j == 0){//just compare the s1 with s3
                    dp[i][j] = dp[i - 1][j] && s1.at(i - 1) == s3.at(i + j - 1);
                }else{
                    //if in the mixed status, dp[i][j] depend on if the s1 match s3 or s2 match s3
                    //dp[i-1][j] try to match s1 and make sure the char in index i - 1 in s1 is
                    //match with wht s3[i +j - 1] (i + j - 1 is current prefix string), dp[i][j-1] try to match s2 
                    dp[i][j] = (dp[i - 1][j] && s1.at(i - 1) == s3.at(i + j - 1)) ||
                        (dp[i][j - 1] && s2.at(j - 1) == s3.at(i + j - 1));
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }
    
    /**
    ** Solution 3 from genius guy
    ** s1, s2只有两个字符串，因此可以展平为一个二维地图，判断是否能从左上角走到右下角。
    ** 当s1到达第i个元素，s2到达第j个元素:
    ** 地图上往右一步就是s2[j-1]匹配s3[i+j-1]。
    ** 地图上往下一步就是s1[i-1]匹配s3[i+j-1]。
    ** 示例：s1="aa",s2="ab",s3="aaba"。标1的为可行。最终返回右下角。
    **     0  a  b
    ** 0   1  1  0
    ** a   1  1  1
    ** a   1  0  1
    */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size())
            return false;
        vector<vector<bool> > path(m+1, vector<bool>(n+1, false));
        for(int i = 0; i < m+1; i ++)
        {
            for(int j = 0; j < n+1; j ++)
            {
                if(i == 0 && j == 0)
                // start
                    path[i][j] = true;
                else if(i == 0)
                    path[i][j] = path[i][j-1] & (s2[j-1]==s3[j-1]);
                else if(j == 0)
                    path[i][j] = path[i-1][j] & (s1[i-1]==s3[i-1]);
                else
                    path[i][j] = (path[i][j-1] & (s2[j-1]==s3[i+j-1])) || (path[i-1][j] & (s1[i-1]==s3[i+j-1]));
            }
        }
        return path[m][n];
    }
    
    //leetcode official solution 4
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()){
            return false;
        }
        //dp[j] sub-string in s2 with range[0, j) is match with s3
        vector<bool> dp(s2.length() + 1, false);
        for(int i = 0; i <= s1.length(); i++){
            for(int j = 0; j <= s2.length(); j++){
                if( i == 0 && j == 0 ){
                    dp[j] = true; //empty string is matched
                }else if(i == 0){// only match the s2
                    dp[j] = dp[j - 1] && s2.at(j - 1) == s3.at(i + j - 1);
                }else if (j == 0){//only match s1
                    dp[j] = dp[j] && s1.at(i - 1) == s3.at(i + j - 1);
                }else{//mixture status, check both
                    dp[j] = (dp[j] && s1.at(i - 1) == s3.at(i + j - 1)) 
                        ||(dp[j - 1] && s2.at(j - 1) == s3.at(i + j - 1));
                }
            }
        }
        return dp[s2.length()];
    }
};