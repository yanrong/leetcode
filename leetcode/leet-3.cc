#include <iostream>
using namespace std;

int lengthOfLongestSubstring2(string s)
{
    int head = 0, tail = 0;
    int maxi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        tail = i;
        for (int j = head; j < tail; j++)
        {
            if (s[j] == s[i])
            {
                head = j + 1;
                break;
            }
            cout<<"head:" << head<<endl;
        }
        maxi = max(tail - head + 1, maxi);
    }
    return maxi;
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