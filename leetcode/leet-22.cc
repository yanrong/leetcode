#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //solution 1 backtrace
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        genMatch(ret, "", n, n);
        return ret;
    }

    void genMatch(vector<string> &ret, string result, int bl, int br){
        if(bl == 0 && br == 0){
            ret.push_back(result);
            return ;
        }

        //if add '(' right must be less or equal left, if not error output (()))(
        if(bl > 0 && bl <= br) genMatch(ret, result + "(", bl - 1, br); 
        if(br > 0 ) genMatch(ret, result + ")", bl, br - 1);
    }

    /****official solution 2***/
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        //for the n pairs , total length is 2 * n
        string temp(2 * n, (char)0);
        generateAll(temp, 0, combinations);
        return combinations;
    }
    void generateAll(string& s, int pos, vector<string>& result){
        if(pos == s.length()){
            if(valid(s)){//if the generate string is valid
                result.push_back(s);
                return;
            }
        }else{//generate the all possible combination
            s[pos] = '(';
            generateAll(s, pos + 1, result);
            s[pos] = ')';
            generateAll(s, pos + 1, result);
        }
    }
    bool valid(string& s){
        int balance = 0;
        for(auto c : s){
            if(c == '(') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        //a valid bracket string, balance is zero 
        return balance == 0;
    }
    /****official solution backtrace*****/
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        backTrace(ret, "", 0, 0, n);
        return ret;
    }

    void backTrace(vector<string>& ret, string cur, int open, int close, int max){
        if(cur.size() == max * 2){
            ret.push_back(cur);
            return;
        }

        if(open < max){
            backTrace(ret, cur + "(", open + 1, close, max);
        }
        if(close < open){
            backTrace(ret, cur + ")", open, close + 1, max);
        }
    }
    /***other way from official leetcode***/
    /***other way in dp
    ***for each combinations, it must be begin with '(' ,  end with ')' without definitely
    ***so enum the all place of ')' as possible. the middle int close brace mys is valid.
    ***the reset valid braces in the right of ')' 
    **** dp[i] = '(' + dp[j] +')' + dp[i -j - 1]
    ***/
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n == 0){
            ret.push_back("");
        }else{
            for(int c = 0; c < n; c++){
                for(string left : generateParenthesis(c)){
                    for(string right : generateParenthesis(n - 1 - c)){
                        ret.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        
        return ret;
    }
};

int main(int argc, const char** argv) {
    vector<string> vec;
    Solution s;
    vec = s.generateParenthesis(9);
    for(auto a : vec) cout << a <<" , ";
    cout << endl;
    return 0;
}