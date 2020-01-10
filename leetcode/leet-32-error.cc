#include<string>
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        string temp;

        if(s.length() < 2) return maxlen;
        for(int i = 0; i < s.length(); i++){
            //sub string range is [pos pos + len) so j should point last one plus 1 position
            for(int j = i + 1; j <= s.length(); j += 1){
                temp = s.substr(i, j);
                cout <<temp <<endl;
                if(isValid(temp)){
                    maxlen = maxlen >= temp.length() ? maxlen : temp.length(); 
                    cout <<"i " << i << " j " << j << " max = " << maxlen <<endl;
                }
            }
        }

        return maxlen;
    }

    bool isValid(string s){
        vector<char> stack;
        for(int i = 0; i < s.length(); i++){
            //'(' always should be push to stack
            if(s[i] == '(' ){
                stack.push_back(s[i]);
            }else if(!stack.empty() && stack.back() == '(' ){ //if stack is not empty
                stack.pop_back(); // and top one is '(' and ')' is coming, pop top element
            }else{
                return false; // the string is not valid
            }
        }

        return stack.empty(); //check if stack is empty, maybe one or more '(' in stack  
    }
};

int main(int argc, const char** argv) {
    Solution s;
    string str = "))))((()((";
    int ret = s.longestValidParentheses(str);
    cout << "ret = "<< ret << endl;
    return 0;
}