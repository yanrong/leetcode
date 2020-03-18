#include <iostream>
#include <string>
#include <vector>
#include <climits>
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

    string longestCommonPrefix2(vector<string>& strs) {
        if(strs.size() == 0) return "";

        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0].at(i);
            for(int j = 1; j < strs.size(); j++){
                if(i == strs[j].size() || c != strs[j].at(i)){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

class Solution {
public:
    /***divide and search***/
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        return longestCommonPrefixRecurse(strs, 0, strs.size() - 1);
    }

    /**binary seach**/
    string longestCommonPrefix2(vector<string>& strs) {
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
private:
    /****devide and search****/
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

    /***binary search***/
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
