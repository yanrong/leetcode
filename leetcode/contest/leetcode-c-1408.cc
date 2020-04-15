#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ret;
        sort(words.begin(), words.end(), [](string s1, string s2) -> bool { return s1.size() < s2.size(); });
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if(containOf(words[i], words[j])){
                    ret.push_back(words[i]);
                    break;
                }
            }
        }

        return ret;
    }
    
    bool containOf(string s1, string s2){
        int sl1 = s1.size();
        int sl2 = s2.size();
        int k, j ,len;

        for(int i = 0; i <= sl2 - sl1; i++){
            len = j = 0;
            k = i;
            while(j < sl1 && s1[j++] == s2[k++]){
                len++;
            }
            if(len == sl1){return true;}
        }
        return false;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<string> words{"blue","green","bliu", "env"};
    vector<string> ret = s.stringMatching(words);
    for(auto ss : ret){
        cout << " " << ss;
    }
    cout <<endl;
    return 0;
}