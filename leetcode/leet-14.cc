#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l1, l2, max_length;
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string maxPrefix = strs[0];

        for(int i = 1; i != strs.size(); i++){
            max_length = l1 = l2 = 0;
            while(l1 < maxPrefix.length() && l2 < strs[i].length()){
                if(maxPrefix[l1] == strs[i][l2]){
                    max_length++;
                    l1++; l2++;
                }else{
                    break;
                }
            }
            maxPrefix = maxPrefix.substr(0, max_length);
        }

        return maxPrefix;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<string> vstr{"genius"};//{"dog","racecar","car"}; //{"flower","flow","flight"};
    cout << s.longestCommonPrefix(vstr) <<endl;
    return 0;
}
