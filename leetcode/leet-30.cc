#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::map;
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        map<string, int> counts;
        string tempStr;
        int elen, slen, nums;

        if(s.length() == 0 || words.size() == 0) return ret;

        elen = words[0].length(); 
        slen = s.length(); 
        nums = words.size();
        
        for(string s : words) counts[s]++; //init every words times shoule be in string, only a time
        //slen - nums * elen -1 represent a whole words combine string
        for(int i = 0; i <= slen - nums * elen; i++){
            map<string, int> frequency;// counts every string times in words
            int j = 0;
            for(; j < nums; j++){
                tempStr = s.substr(i + j * elen, elen); //get a substring
                if(counts.find(tempStr) != counts.end()){
                    frequency[tempStr]++;// find one add it's counter
                    if(frequency[tempStr] > counts[tempStr]) break;//if times above 1, break it
                }else break;//is words do not contain the string, invalid
            }
            
            if(j == nums) ret.push_back(i);
        }

        return ret;
    }

    vector<int> findSubstring2(string s, vector<string>& words) {
        vector<int> ret;
        int len = s.length(), nums = words.size(), elen;
        map<string, int> counts;
        string tempStr;
        if(s.empty() || words.empty()) return ret;
        
        elen = words[0].length();
        for(auto ss : words) counts[ss]++;

        for(int i = 0; i < elen; i++){
            int left = i, count = 0;
            map<string, int> wd;

            for(int j = i; j <= len - elen; j += elen){
                tempStr = s.substr(j, elen);

                if(wd.count(tempStr)){
                    wd[tempStr]++;
                    if(wd[tempStr] <= counts[tempStr]){
                        count++;
                    }else{
                        while(wd[tempStr] > counts[tempStr]){
                            string t = s.substr(left,elen);
                            wd[t]--;
                            if(wd[t] < counts[t]) count--;
                            left += len;
                        }
                    }

                    if(count == nums){
                        ret.push_back(left);
                        wd[s.substr(left, len)]--;
                        count--;
                        left += len;
                    }
                }else{
                    wd.clear();
                    count = 0;
                    left = j + len;
                }
            }
        } 

        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    string str("addstringtotext");
    vector<string> v{"ad","ds"};
    vector<int> ret = s.findSubstring2(str, v);
    
    for(auto sk : ret) cout << sk;
    cout << endl;
    return 0;
}