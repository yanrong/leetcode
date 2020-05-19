#include <string>
#include <algorithm>
using std::max;
using std::string;
using std::min;

class Solution {
public:
    //dynamic programming
    /*********************************************/
    string longestPalindrome(string s) {
        int maxLen = 1, pos;
        int len = s.size();
        if (len <= 1)//a char is palindromic
            return s;
        bool dp[len][len] = {false}; //dp[i][j] represent substring from i to j is palindromic string
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = true; //sub string from index i to i must be palindromic
        }

        for (int i = 0; i < len - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true; //if adjacent two char is palindromic, mark it
                maxLen = 2;
                pos = i;
            }
        }
        for(int k = 3; k <= len; k++){ //init span, a and increment to whole length
            for(int i = 0; i <= len - k; i++){
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]){ //judge from third char, if it is equal and sub string is parlindromic
                    dp[i][j] = true;
                    pos = i;
                    maxLen  = k;
                }
            }
        }

        return s.substr(pos, maxLen);
    }
    //expand in center
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return s;
        int maxlen = 0, left = 0, right = 0, substr_left, substr_right, substr_len;
        string max_sub_string = "";
        for(int i = 1; i<len; ++i){
            left = i - 1 ;
            right = i;
            // even Palindrome  eg. "abba"
            while(left >= 0 && right < len && s[left] == s[right]){
                --left;
                ++right;
            }
            substr_left = left + 1;
            substr_right = right - 1;
            substr_len = substr_right - substr_left + 1 ;
            if(substr_len > maxlen){
                max_sub_string = s.substr(substr_left, substr_len);
                maxlen = substr_len;
            }

            // odd Palindrome eg. "abcba"
            left = i - 1;
            right = i + 1;
            while(left >=0 && right < len && s[left] == s[right]){
                --left;
                ++right;
            }
            substr_left = left + 1;
            substr_right = right - 1;
            substr_len = substr_right -substr_left + 1 ;
            if(substr_len > maxlen){
                max_sub_string = s.substr(substr_left, substr_len);
                maxlen = substr_len;
            }   
        }
        return max_sub_string;
    }
    /********another excellent solution for expand in center zhihu************/
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
            if(len > end - start){
                start = i - (len - 1) /2;
                end = i + len / 2;
            }
        }
        //s.substr(start, end); // cpp substr - get string from start with len end 
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right){
        int l = left, r = right;
        while( l >= 0 && r < s.size() && s[l] == s[r]){
            l--; r++;
        }

        return r - l - 1;
    }
    /*********************manacher algorithm*************************/
    string getString(string s)
    {
        string str;

        str += '$';
        str += '#';
        for (int i = 0; i < s.length(); i++)
        {
            str += s[i];str += '#';
        }
        str += "^";
        return str;
    }

    string longestPalindrome(string s)
    {
        string str = getString(s); 
        int maxLen = 0, n = str.length();
        //mx is the right most border, id is the right most center index of palindrome 
        int id, pos, mx = 0;
        //p[i] indicate the radius length of palindrome that take the s[i] as center
        //p[i] - 1 exactly is the palindrome length of original string
        int p[n] = {0};
        //the index from 1 to last one, the first char is fill with other char
        for (int i = 1; i < n; i++)
        {
            if (i < mx){ //if in range
                //as if we have know the palindrome radius length from index 0 to i - 1
                //the index i palindrome length radius is the i mirror index palindrome length
                // and mx - i 
                p[i] = min(p[2 * id - i], mx - i);
            } else { // out of range
                p[i] = 1;
            }
            //expand the in center index i 
            while (str[i - p[i]] == str[i + p[i]]) {
                p[i]++;
            }
            //if the new radius is out of current right most, update the all 
            if (mx < i + p[i]) {
                id = i;
                mx = i + p[i];
            }
            //get the max length
            if(maxLen > p[i] - 1) {
                pos = i;
                maxLen = p[i];
            }
        }

        return s.substr(pos, maxLen - 1); //border plus 1
    }
};