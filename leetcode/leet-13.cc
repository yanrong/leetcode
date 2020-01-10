#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        string rmKey[] = {"M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int digKey[] =   {1000, 900,  500, 400,  100,  90,   50,  40,   10,  9,    5,   4,    1};
        int index = 0;

        for(int i = 0; i < s.length();){
           if(s.substr(i, 1) == rmKey[index]){
                ret += digKey[index];
                i++;
            }else if(s.substr(i, 2) == rmKey[index]){
                ret += digKey[index];
                i += 2;
            }else{
                index++;
            }
            cout <<s.substr(i, 2) <<" "<<s.substr(i, 1)<<" ret = "<< ret<<endl;
        }
        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.romanToInt("III") << endl;;
    return 0;
}