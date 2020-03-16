#include <string>
using std::string;
class Solution
{
public:
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
        int max_len = 0;

        int id , pos, mx = 0;
        int p[str.length()] = {0};

        for (int i = 1; i < str.length(); i++)
        {
            if (i < mx)
                p[i] = p[2 * id - i] < mx - i ? p[2 * id - i] : mx - i ; 
            else
                p[i] = 1;

            while (str[i - p[i]] == str[i + p[i]])
                p[i]++;

            if (mx < i + p[i])
            {
                id = i;
                mx = i + p[i];
            }

            if(max_len > p[i] - 1){
                pos = i;
                max_len = p[i];
            }
        }

        return s.substr(pos, max_len - 1); //border plus 1
    }
};