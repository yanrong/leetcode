#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        char top, tmp;
        if(!s.length()) return true;

        for(char i : s){
            if(stack.empty()){
                stack.push_back(i);
            }else{
                top = stack.back();
                tmp = getMatch(top);
                if(tmp == i) stack.pop_back();
                else stack.push_back(i);
                //cout <<"i "<< i << " top " << top << " tmp " << tmp <<endl;
            }

            for(char ccc : stack) cout << ccc<< " ";
            cout <<endl;
        }

        cout << stack.empty() <<endl;
        return stack.empty();
    }
    char getMatch(char c){
        map<char,char> mapChar = {
            {'(', ')' },
            {'[', ']' },
            {'{', '}' },
        };
        
        for(auto p : mapChar){
            if(p.first == c) return p.second;
        }
        return 0;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    string str("([{}{[}[]])");
    string valid = s.isValid(str) ? "true" : "false";
    cout << valid << endl;
    return 0;
}
