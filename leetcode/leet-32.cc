#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
using std::max;
using std::cout;
using std::endl;

class Solution {
public:
    int longestValidParentheses(string s) {
         int max_len = 0, len = s.size();
        
        if (len < 2) return 0;
        int dp[len] = {0};
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = ((i >= 2) ? dp[i - 2] : 0) + 2;
                } else {
                    if ((i - dp[i - 1]) > 0 and s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                }

                max_len = max(max_len, dp[i]);
            }
        }

        //for(int i =0 ; i < len; i++) cout << dp[i] << " " ; cout<< endl;
        return max_len;
    }

    int longestValidParentheses2(string s) {
        int maxlen = 0;
        if (s.length() < 2) return 0;
        vector<int> stack;
        stack.push_back(-1);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                stack.push_back(i);
            }else{
                stack.pop_back();
                if(stack.empty()){
                    stack.push_back(i);
                }else{
                    maxlen = max(maxlen, i - stack.back());
                }
            }
            cout << "maxlen = " <<maxlen <<endl;
            for(auto cj : stack) cout << cj << " "; cout << endl;
        }

        return maxlen; 
    }

    int longestValidParentheses2(string s) {
        int maxlen = 0, left = 0, right = 0;
        if (s.length() < 2) return 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') {
                left++;
            } else {
                right++;
            }
        }
    }
};

int main(int argc, const char** argv) {
    Solution s;
    string str("()");
    int ret = s.longestValidParentheses2(str);
    cout << "ret = " << ret <<endl;
    return 0;
}