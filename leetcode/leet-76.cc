#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
using std::string;
using std::vector;
using std::unordered_map;

class Solution {
public:
    //sliding window
    /**
    ** 1.初始，left 指针和 right指针都指向 S的第一个元素.
    ** 2.将 right针右移，扩张窗口，直到得到一个可行窗口，亦即包含 T 的全部字母的窗口。
    ** 3.得到可行的窗口后，将 left 指针逐个右移，若得到的窗口依然可行，则更新最小窗口大小。
    ** 4.若窗口不再可行，则跳转至 2 。
    */
    string minWindow(string s, string t) {
        unordered_map<char, int> window, needs;
        int r = 0, l = 0;
        int start, count, minLen = INT_MAX;
        char c1, c2;
        
        if(s.length() == 0 || t.length() == 0){
            return "";
        }
        //first init the t's map, counter each char counter number
        for(auto c : t){
            needs[c]++;
        }
        count = 0;
        
        while(r < s.size()){
            c1 = s[r];
            //expand to right
            if(needs.count(c1)){
                window[c1]++;
                if(window[c1] == needs[c1]){
                    //if the char is valid, expand the window valide size
                    count++;
                }
            }
            r++;
            //fixe the window size, so resize the window to minimum
            while(count == needs.size()){
                if(r - l < minLen){
                    start = l;
                    minLen = r - l;
                }
                c2 = s[l];
                //if the window has the key
                if(needs.count(c2)){
                    window[c2]--;//decrease the counter
                    if(window[c2] < needs[c2]){ //if the char has been delete from the window
                        count--; // decrease the current window size
                    }
                }
                l++;//shift the index left
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
    /***solution 2 a kind of simplify code***/
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        int left = 0, cnt = 0, minLen = INT_MAX;
        for (char c : t) {
            ++letterCnt[c];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (--letterCnt[s[i]] >= 0) ++cnt;
            //reach the window size
            while (cnt == t.size()) {
                if (minLen > i - left + 1) {
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) --cnt;
                ++left;
            }
        }
        return res;
    }
    //solution from leetcode genius 
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int left = 0, count = 0, start = 0, maxLen = INT_MAX; 
        
        for(auto c : t){
            hash[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(--hash[s[i]] >= 0){
                count++;
            }
            
            while(count == t.size()){
                if(maxLen > i - left + 1){
                    maxLen = i - left + 1;
                    start = left;
                }
                if(++hash[s[left]] > 0) count--;
                left++;
            }
        }
        return maxLen == INT_MAX ? "" : s.substr(start, maxLen);
    }
};