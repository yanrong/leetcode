#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::sort;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int length = words.size();
        if(words.size() <= 1) return words;
        sort(words.begin(), words.end(), [](string s1, string s2)->bool{return s1.length() > s2.length();});
        
        return ret;
    }
};

