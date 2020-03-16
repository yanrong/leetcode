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
        //slen - nums * elen represent a whole words combine string
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
        vector<int>ret;
        map<string,int> counts;
        string tempStr;
        int slen = s.length(), nums = words.size(), elen;
        
        if(s.empty() || words.empty()) return ret;

        elen = words[0].length();
        for(auto ws : words) counts[ws]++;

        for(int i = 0; i < elen; i++){
            int left = i, count = 0; //left from beginning of indices
            map<string, int> freq;
            for(int j = i; j <= slen - elen; j += elen){
                tempStr = s.substr(j, elen);
                if(counts.count(tempStr)){//if string is existence in words
                    freq[tempStr]++; //mark it appear times
                    if(freq[tempStr] <= counts[tempStr]){//if a string appear in the first time
                        count++; //counter how many string in words has been appera in string
                    }else{
                        while(freq[tempStr] > counts[tempStr]){//if mutiple appear
                            string temp = s.substr(left, elen); // get sub string
                            freq[temp]--; //reduce it appear times
                            if(freq[temp] < counts[temp]) count--; //this string has been deleted from counts,decrease whole matched counter 
                            left += elen; //skip it 
                        }
                    }

                    if(count == nums){ //whole string in words has been matched
                        ret.push_back(left);// remember the a site
                        freq[s.substr(left, elen)]--;
                        count--;
                        left += elen;
                    }
                }else{
                    freq.clear();
                    count = 0;
                    left = j + elen;
                }
            }
        }

        return ret;
    }
};

int main(int argc, const char* argv[]){
    Solution s;
    string s1("barfoothefoobarman"), s2("wordgoodgoodgoodbestword");
    vector<string> words{"foo","bar"}, words2{"word","good","best","word"};
    vector<int> ret = s.findSubstring2(s1, words);
    cout << "[";
    for(auto cc : ret) cout <<" "<<cc<<" ";
    cout <<"]" << endl;
    return 0;
}