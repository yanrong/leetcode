#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
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
};

int main(int argc, const char** argv) {
    vector<string> vec;
    Solution s;
    vec = s.generateParenthesis(9);
    for(auto a : vec) cout << a <<" , ";
    cout << endl;
    return 0;
}