#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> strMap{"","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        getResult(result, digits, 0, "", strMap);

        return result;
    }

    void getResult(vector<string> &result, string digits, int index, string res, vector<string> strMap){
        
        if(/*res.size() == digits.size() ||*/ index == digits.size()){
            if(res.length()) result.push_back(res); //avoid "" output error
            return ;
        }else{
            string temp = strMap[digits[index] - '1'];
            for(int i = 0; i < temp.length(); i++){
                string tmpStr = res + temp[i]; //every step, generate a new string to store final result;
                getResult(result, digits, index + 1, tmpStr, strMap);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> ret = s.letterCombinations("3");
    for(string s : ret) cout << s << " ";
    cout << endl;
    return 0;
}
