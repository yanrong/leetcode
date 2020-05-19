#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    //original solution 1, too redundancy
    string longestCommonPrefix(vector<string>& strs) {
        int l1, l2, maxLength;
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        //alway chose the maxPrefix as the common prefix
        string maxPrefix = strs[0];

        for(int i = 1; i != strs.size(); i++){
            maxLength = l1 = l2 = 0;
            while(l1 < maxPrefix.length() && l2 < strs[i].length()){
                if(maxPrefix[l1] == strs[i][l2]){
                    maxLength++;
                    l1++; l2++;
                }else{
                    break;
                }
            }
            maxPrefix = maxPrefix.substr(0, maxLength);
        }

        return maxPrefix;
    }
    
    //official solution 2 compare each char 
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        //the solution is genius idea, we take the strs[0] as the compare object
        //longest common prefix is dependent on the strs[0] or the sub-string get from the strs[0]
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0].at(i); // take the each char in strs[0] tow examine the rest string
            for(int j = 1; j < strs.size(); j++){
                //if we get the smallest strs[i] or the c is not contian in a string
                if(i == strs[j].size() || c != strs[j].at(i)){
                    return strs[0].substr(0, i); // get the sub string in range [0, i - 1]
                }
            }
        }
        return strs[0]; // we finish the whole compare and strs[0] must be the right answer
    }

    /*** official Solution 3 divide and search***/
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        return longestCommonPrefixRecurse(strs, 0, strs.size() - 1);
    }
    string longestCommonPrefixRecurse(vector<string>& strs, int left, int right){
        if(left == right){
            return strs[left];
        }else{
            int mid = (left + right) / 2;
            string lcpLeft = longestCommonPrefixRecurse(strs, left, mid);
            string lcpRight = longestCommonPrefixRecurse(strs, mid + 1, right);

            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    string commonPrefix(string left, string right){
        int minLen = min(left.size(), right.size());
        for(int i = 0 ; i < minLen; i++){
            if(left.at(i) != right.at(i)){
                return left.substr(0, i);
            }
        }
        return left.substr(0, minLen);
    }
    
    /**official solution 4 binary seach scan in vertical**/
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        int minLen = INT_MAX;
        for(auto str : strs){
            minLen = min(minLen, (int)str.size());
        }
        int low = 1, hight = minLen;

        while(low <= hight){
            int middle = (low + hight) / 2;
            if(isCommonPrefix(strs, middle)){
                low = middle + 1;
            }else{
                hight = middle -1;
            }
        }

        return strs[0].substr(0, (low + hight) / 2);
    }
    bool isCommonPrefix(vector<string>& strs, int len){
        string str1 = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0, k = 0; j < strs[i].size() && k < str1.size(); j++, k++){
                if(strs[i][j] != str1[k]) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<string> vstr{"genius"};//{"dog","racecar","car"}; //{"flower","flow","flight"};
    cout << s.longestCommonPrefix(vstr) <<endl;
    return 0;
}
