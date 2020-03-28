#include <string>
#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::string;
using std::stack;
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

    int longestValidParentheses3(string s) {
        int maxlen = 0, left = 0, right = 0;
        if (s.length() < 2) return 0;
        //detect like ((
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if(left == right){ // if equal ,they must have a valid string
                maxlen = max(maxlen, 2 * right);
            }else if(right >= left){
                left = right = 0;
            }
        }

        left = right = 0;
        //detected like ))
        for(int i = s.length(); i >= 0; i--){
            if(s[i] == '(' ){
                left++;
            }else{
                right++;
            }

            if(left == right){
                maxlen = max(maxlen, 2 * left);
            }else if(left >= right){
                left = right = 0;
            }
        }

        return maxlen;
    }
    
    /**official solution 4 over limit time**/
    int longestValidParentheses(string s) {
        int maxlen = 0;
        string temp;

        if(s.length() < 2) return maxlen;
        for(int i = 0; i < s.length(); i++){
            //sub string range is [pos pos + len) so j should point last one plus 1 position
            for(int j = i + 2; j <= s.length(); j += 2){
                temp = s.substr(i, j - i);
                
                if(isValid(temp)){
                    maxlen = max(maxlen, j - i); 
                }
            }
        }

        return maxlen;
    }

    bool isValid(string s){
        stack<char> vstack;
        for(int i = 0; i < s.length(); i++){
            //'(' always should be push to stack
            if(s[i] == '(' ){
                vstack.push('(');
            }else if(!vstack.empty() && vstack.top() == '(' ){ //if stack is not empty
                vstack.pop(); // and top one is '(' and ')' is coming, pop top element
            }else{
                return false; // the string is not valid
            }
        }

        return vstack.empty(); //check if stack is empty, maybe one or more '(' in stack  
    }
};

int main(int argc, const char** argv) {
    Solution s;
    string str("()");
    int ret = s.longestValidParentheses2(str);
    cout << "ret = " << ret <<endl;
    return 0;
}