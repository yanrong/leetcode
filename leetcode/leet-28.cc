#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        vector<int> kmp(needle.length() + 1, 0);
        if(haystack.empty() && !needle.empty()) return -1;
        if(needle.empty()) return 0;
        
        getNext(needle, kmp);
        //for(auto cc:kmp) cout <<cc <<" "; cout <<endl;
        while(i < haystack.length())
        {
            if(j == -1 || haystack[i] == needle[j]){
                i++; j++;
            }else{ 
                j = kmp[j];;
            }
            //cout << "j " << j <<" i " <<i <<endl;
            if(j == needle.length()) return i - needle.length();
        }
        
        return -1;
    }

    void getNext(string s, vector<int> &kmp){
        int i = -1, j = 0;
        kmp[0] = -1;
        while(j < s.length() - 1){
            if(i == -1 || s[i] == s[j]){
                i++; j++;
                if(s[i] == s[j]) kmp[j] = kmp[i];
                else kmp[j] = i;
            }else{
                i = kmp[i];
            }    
        } 
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ret;
    string s1("mississippi"), s2("issip");
    string s3("cdbcdfcdcdadf"), s4("cdcda");
    ret = s.strStr(s3, s4);
    cout <<"ret = " << ret << endl;
    return 0;
}
