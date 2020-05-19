#include <iostream>
#include <climits>
#include <string>
#include <cctype>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    //original solution 1
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
//official solution
class Automaton {
private:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};


int main(int argc, const char **argv)
{
    Solution s;
    cout << "s " << s.myAtoi("20000000000000000000") << endl;
    return 0;
}