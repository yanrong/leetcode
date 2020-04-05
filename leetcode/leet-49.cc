#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using std::swap;
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> keys;
        unordered_map<string, vector<string>> strMap;
        string tmp;
        for(int i = 0; i < strs.size(); i++){
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());

            if(strMap.count(tmp)){
                strMap[tmp].push_back(strs[i]);
            }else{
                keys.push_back(tmp);
                strMap[tmp] = vector<string>(1, strs[i]);
            }
        }
        
        for(int i = 0; i < keys.size(); i++){
            result.push_back(strMap[keys[i]]);
        }
        return result;
    }
    //official solution
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> strMap;
        vector<int> count;
        string tmp;
        for(auto s : strs){
            count.assign(26, 0);
            //count the frequency of each char in string
            for(auto c : s) count[c - 'a']++;
            tmp = "";
            for(int i = 0; i < 26; i++){
                //generate a mix unique string, format like ＃1＃2＃3＃0＃0＃0 ...＃0
                //the number show the correspond counter from a - z
                tmp += "#" + to_string(count[i]);
            }
            if(strMap.count(tmp)){strMap[tmp].push_back(s);}
            else{ strMap[tmp] = vector<string>(1, s); }
        }
        
        for(auto vs : strMap){
            result.push_back(vs.second);
        }
        return result;
    }
    
    //official solution
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int a[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        unordered_map<double, vector<string>> M;
        for(string& s: strs){
            double key = 1;
            for(char& c: s)
                key *= a[c-'a'];
            M[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& p : M)
            ans.push_back(p.second);
        return ans;
    }
};

//OVERFLOW Failed
class Solution {
public:
    long hashStr(string s){
        long sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum = (sum * 26 + s[i] - 'a') % (INT_MAX - 1); 
        }
        return sum;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<long, vector<string>> strMap;
        long key;

        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            key = hashStr(tmp);
            strMap[key].push_back(strs[i]);
        }
        for(auto& p : strMap){
            result.push_back(p.second);
        }
        return result;
    }
};