#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    //original solution
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> mapChar = {
            {'(', ')' },
            {'[', ']' },
            {'{', '}' },
        };

        char top, tmp;
        if(!s.length()) return true;

        for(char i : s){
            if(stack.empty()){
                stack.push_back(i);
            }else{
                top = stack.back();
                //if the char is exist get it or return'#'
                tmp =  mapChar.count(top) ? mapChar[top] : '#';
                if(tmp == i) {// if the current char is equal to stack top data. pop it
                    stack.pop_back();
                } else {//else push it to stack
                    stack.push_back(i);
                }
            }
        }
        //if the stack is empty, the string is valid
        return stack.empty();
    }
    //official solution
    bool isValid(string s) {
        stack<char> charStack;
        unordered_map<char,char> mapChar = {
            {')', '(' },
            {']', '[' },
            {'}', '{' },
        };

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            //if the char is ( [ { push it to stack, otherwise check if it is matched
            if(mapChar.find(c) != mapChar.end()){
                char top = charStack.empty() ? '#' : charStack.top();
                if(top != mapChar.at(c)){//if there a char is dismatch, return false
                    return false;
                }
                charStack.pop();
            }else{
                charStack.push(c);
            }
        }
        return charStack.empty();
    }
};

int main(int argc, const char** argv) {
    Solution s;
    string str("([{}{[}[]])");
    string valid = s.isValid(str) ? "true" : "false";
    cout << valid << endl;
    return 0;
}
