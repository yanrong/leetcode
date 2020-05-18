#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    //leetcode official solution
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
    
    int lengthOfLongestSubstring2(string s)
    {
        int n = s.size();
        //use the a set to count the unique char
        unordered_set<char> unique_set;
        //i is unique left, j is unique right
        int ret = 0, i = 0, j = 0;
        while(i < n && j < n){
            if(!unique_set.count(s[j])){
                unique_set.insert(s[j++]);
                //if the char is unique, count the max length
                ret = max(ret, j - i);
            }else{
                //delete the char and move the index forward
                unique_set.erase(s[i++]);
            }
        }
        return ret;
    }

    int lengthOfLongestSubstring3(string s)
    {
        int n = s.size(), ret = 0;
        //key - value key represent the char, value is index of char
        unordered_map<char, int> umap;
        for(int i = 0, j = 0; j < n; j++){
            if(umap.count(s[j])){//if the key has been in map
                i = max(umap[s[j]], i); //get key s[j] index and get max one among with i
            }
            ret = max(ret, j - i + 1); //every step, recalculate max length
            umap[s[j]] = j + 1;// and insert key - value the
        }
        return ret;
    }
    //original solution ???
    int lengthOfLongestSubstring(string s)
    {
        int i, j, pos = 0;
        int maxLen = 0;
        //select the s[i] as a key to check if there exist in sub string s[0, i - 1]
        for (i = 0; i < s.length(); i++)
        {
            for (j = pos; j < i; j++)
            {
                if (s[i] == s[j])
                {// if exist, record the pos, and skip the loop 
                    pos = j + 1;
                    break;
                }
            }
            //get max one(i - pos + 1) is the current unique string
            maxLen = max((i - pos + 1), maxLen);
        }
        return maxLen;
    }
};

int main()
{
    Solution s;
    string s("a");
    int n = s.lengthOfLongestSubstring(s);

    cout << "n = " << n << endl;
}