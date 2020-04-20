#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    /**KMP solution**/
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        vector<int> kmp(needle.length() + 1, 0);
        if(haystack.empty() && !needle.empty()) return -1;
        if(needle.empty()) return 0;
        
        getNext(needle, kmp);
        while(i < haystack.length())
        {
            if(j == -1 || haystack[i] == needle[j]){
                i++; j++;
            }else{ 
                j = kmp[j];
            }
            if(j == needle.length()) return i - needle.length();
        }
        
        return -1;
    }

    /**create next, find comparing string should be 
     * back to position when dismatch with pattern string
     **/
    void getNext(string s, vector<int> &kmp){
        int i = -1, j = 0;
        kmp[0] = -1;
        while(j < s.length()){
            if(i == -1 || s[i] == s[j]){
                i++; j++;
                if(s[i] == s[j]) kmp[j] = kmp[i];
                else kmp[j] = i;
            }else{
                i = kmp[i];
            }    
        } 
    }
    
    /**solution from official [Rabin Karp]**/
    //covert character to integer
    int char2int(int idx, string s){
        return (int)s.at(idx) - int('a');
    }

    int strStr(string haystack, string needle) {
        int l = needle.length(), n = haystack.length();
        if(l > n)  return -1;

        //base value for the rolling has function
        int a = 26;
        // modulus value for the rolling hash function to avoid overflow
        long modules = (long)pow(2, 31);
        // compute the hash of strings haystack[:L], needle[:L]
        long h = 0, ref_h = 0;
        for(int i = 0; i < l; i++){
            h = (h * a + char2int(i, haystack)) % modules;
            ref_h = (ref_h * a + char2int(i, needle)) % modules;
        }

        if(h == ref_h) return 0;
        // const value to be used often : a**L % modulus
        long al = 1;
        for(int i = 1; i <= l; i++) al = (al * a) % modules;

        for(int start = 1; start < n - l + 1; start++){
            // compute rolling hash in O(1) time
            h = (h * a - char2int(start - 1, haystack) * al + char2int(start + l - 1, haystack)) % modules;
            if(h == ref_h) return start;
        }
        return -1;
    }

    /********************ordinay solution***********************/
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
    ret = s.strStr(s3, s4);
    cout <<"ret = " << ret << endl;
    return 0;
}
