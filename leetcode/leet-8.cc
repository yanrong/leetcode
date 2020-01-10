#include <iostream>
#include <climits>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        string::const_iterator i;
        bool negative = false ,mark = false;;
        long long ret = 0;
        for (i = str.begin(); i != str.end(); i++)
        {
            if (isspace(*i))
                continue;
            if (isalpha(*i))
                return 0;
            if (*i == '-')
                negative = true;
            if (*i == '+') mark = true;
            break;
        }

        if (negative == false){
            if(mark) i++ ;
            while (i != str.end() && isdigit(*i))
            {
                ret = ret * 10 + (*i - '0');
                i++;
                if(ret > INT_MAX) return INT_MAX;
            }
        }else{
            i++; //skip the negative - 
            while (i != str.end() && isdigit(*i))
            {
                ret = ret * 10 - (*i - '0');
                i++;
                if(ret < INT_MIN) return INT_MIN;
            }
        }
    
        return ret;
    }
};

int main(int argc, const char **argv)
{
    Solution s;
    cout << "s " << s.myAtoi("20000000000000000000") << endl;
    return 0;
}