#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::sort;

class Solution {
public:
    //origin solution, greedy algorithm
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int length = words.size();
        int idx = 0;
        //in case to overflow in words[0]
        if(words.size() < 1) return words;
        //first one shoule be add to result
        ret.push_back(words[0]);
        //greedy to add more words as possible
        for(int i = 1; i < length; i++){
            //if this one should be add to
            if(ret[idx].length() + words[i].length() < maxWidth){
                //connect with " " to eache one
                ret[idx] += " " + words[i];
                continue;
            }else{
                idx++;
                //now a new line add to ret
                ret.push_back(words[i]);
            }
        }
        //shuffle the string length to maxWidth
        for(int i = 0; i < ret.size(); i++){
            reShuffle(ret[i], maxWidth, i == (ret.size() - 1));
        }
        return ret;
    }

    void reShuffle(string& s, int maxWidth, bool isLast){
        vector<int> pos;
        //first counter how many space has been exist
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                pos.push_back(i);
            }
        }
        //if no space or the last one, we just need add the space to string end 
        // until the string length is less the maxWidth
        if(pos.size() == 0 || isLast){
            while(s.length() < maxWidth){
                s.push_back(' ');
            }
        }else{
            while(s.length() < maxWidth){
                //now we try to fill the space in each space position in thr origin data
                //and make sure the string length is less maxWidth
                for(int i = 0; i < pos.size() && s.length() < maxWidth; i++){
                    s.insert(s.begin() + pos[i], ' ');
                    for(int j = i + 1; j < pos.size(); j++){
                        pos[j]++;
                    }
                }
            }
        }
    }
};

