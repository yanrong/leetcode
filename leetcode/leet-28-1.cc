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
        while(i < haystack.length() && j < needle.length()){
            if(haystack[i++] == needle[j++]); // if compare result is same, skip to next
            else{ i -= j - 1; j = 0;}// else, search-string back to the place except the common part that get from this comparison
        }
        //if we have been search the whole string, i - j is right place  
        return  j == needle.length() ? i - j: -1;
    }
    
    /**official solution violence enumeration all possible sub-string**/
    int strStr(string haystack, string needle) {
        int l = needle.size(), n = haystack.size();
        
        for(int start = 0; start < n - l + 1; start++){
            if(haystack.substr(start, l) == needle){
                return start;
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        int l = needle.size(), n = haystack.size();
        if(l == 0) return 0;
        int pn = 0;
        while(pn < n - l + 1){
            // find the position of the first needle character
            // in the haystack string
            while((pn < n - l + 1) && haystack.at(pn) != needle.at(0)){
                pn++;
            }
            // compute the max match string
            int curLen = 0, pl = 0;
            while(pl < l&& pn < n && haystack.at(pn) == needle.at(pl)){
                pn++;
                pl++;
                curLen++;
            } 
            // if the whole needle string is found,
            // return its start position
            if (curLen = l) return pn - l;
            // otherwise, backtrack
            pn = pn - curLen + 1;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ret;
    string s1("mississippi"), s2("issip");
    string s3("cdbcdfcdcdadf"), s4("cdcda");
    ret = s.strStr("", "t");
    cout <<"ret = " << ret << endl;
    return 0;
}
