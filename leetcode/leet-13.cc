#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        string rmKey[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int digKey[] =   {1000, 900,  500, 400,  100,  90,   50,  40,   10,  9,    5,   4,    1};
        int index = 0;

        for(int i = 0; i < s.length();){
            if(s.substr(i, 1) == rmKey[index]){ //if a char is valid
                ret += digKey[index];
                i++;
            }else if(s.substr(i, 2) == rmKey[index]){ // if two char is valid
                ret += digKey[index];
                i += 2;
            }else{//the index is invalid, skip index
                index++;
            }
        }
        return ret;
    }
    //leetcode solution
    int romanToInt(string s) {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)]; // MSB must be a char
        for(int i = 1; i < s.size(); ++i){//from the index 1 to last one data
            string two = s.substr(i - 1, 2);//get the two char
            string one = s.substr(i, 1); // get one char
            //key - value, check which one is valid, and get sum
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.romanToInt("III") << endl;;
    return 0;
}