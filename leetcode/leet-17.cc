#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    //solution 1 BFS Original solution ???
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> strMap{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if(digits.length() == 0) return result;
        result.push_back("");//push a empty string in first

        for(int i = 0; i < digits.length(); i++){
            int size = result.size();
            //scan the all string in result
            for(int j = 0; j < size; j++){
                string top = result.front();// get top
                result.erase(result.begin()); // remove it, further generate will contain it
                //the digits number in range [2, 9], get the map string of digits[i],
                //the digits[0] is empty string, there will not add any more data, 
                //after 
                for(int l = 0; l < strMap[digits[i] - '1'].size(); l++){ // get the map string
                    result.push_back(top + strMap[digits[i] - '1'][l]); //combine top and each char in strMap[l], generate a new string
                }
            }
        }
        return result;
    }
    //solution 2 DFS leetcode official solution
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> strMap{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backTrace(result, digits, 0, "", strMap);

        return result;
    }

    void backTrace(vector<string> &result, string digits, int index, string res, vector<string> strMap){
        if(index == digits.size()){//if the res length is equal to original digits length, finish trace
            //avoid "" output error
            if(res.length() != 0) result.push_back(res); 
            return ;
        }else{
            string temp = strMap[digits[index] - '1']; // get the map string with index 'index'
            for(int i = 0; i < temp.length(); i++){
                 //every step, generate a new string to store temporary result;
                string tmpStr = res + temp[i];
                backTrace(result, digits, index + 1, tmpStr, strMap);
            }
        }
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<string> ret = s.letterCombinations("3");
    for(string s : ret) cout << s << " ";
    cout << endl;
    return 0;
}
