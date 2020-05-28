#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    //leetcode solution from Internet cnblog
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s.at(0) == '0') return 0;
        //dp[i] the sub-string[0, i) decode ways
        vector<int> dp(n + 1, 0);
        dp[0] = 1;//a char has an decode ways
        for(int i = 1; i <= n; i++){
            //if the previous char is 0, it can't be decode alone, we try judge if 
            //can be decoded that combination with the before one char than it
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            //if the char s[i - 2] is '1' or '2' this is valid, s[i - 1] is in valid range
            // only check the s[i - 1] <= '6', s[i - 1] = 0 has been checked
            if(i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
    //from leetcode genius
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        //pre --- a char decode way, cur -- two char decode way and sum
        int pre = 1, cur = 1;

        //alike fibonacci 
        for (int i = 1; i < s.size(); i++) {
            int temp = cur;
            if (s[i] == '0'){
                if (s[i - 1] == '1' || s[i - 1] == '2'){
                    cur = pre;
                }else{ 
                    return 0;
                }
            }else{ 
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')){
                    cur = cur + pre;
                }
            }
            pre = temp;
        }
        return cur;
    }

    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int a = 1, b = 1, n = s.size();
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') a = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                a = a + b;
                b = a - b;
            } else {
                b = a;
            }
        }
        return a;
    }
};