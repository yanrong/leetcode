#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring2(string s)
{
    int n = s.size();
    unordered_set<char> unique_set;

    int ret = 0, i = 0, j = 0;
    while(i < n && j < n){
        if(!unique_set.count(s[j])){
            unique_set.insert(s[j++]);
            ret = max(ret, j - i);
        }else{
            unique_set.erase(s[i++]);
        }
    }

    return ret;
}

int lengthOfLongestSubstring3(string s)
{
    int n = s.size(), ret = 0;
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

int lengthOfLongestSubstring(string s)
{
    int i, j, pos = 0;
    int max = 0;
    for (i = 0; i < s.length(); i++)
    {
        for (j = pos; j < i; j++)
        {
            if (s[i] == s[j])
            {
                pos = j + 1;
                break;
            }
        }
        max = max > (i - pos + 1) ? max : (i - pos + 1);
    }
    return max;
}

int main()
{
    string s("a");
    int n = lengthOfLongestSubstring(s);

    cout << "n = " << n << endl;
}