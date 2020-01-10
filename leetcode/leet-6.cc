#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
/*
class Solution {
public:
    string convert(string s, int numRows) {
        string str;
        int n = s.length();
        if(numRows == 1) return s;
        for(int j = 0; j < numRows; j++)
            for(int i = 0; (i - j) < n; i += (2 * numRows - 2))
            {
                if(i - j > 0 && j != 0 && j != (numRows - 1))
                    str += s[i - j];
                if((i +j ) < n)
                    str += s[i + j];
            }
        return str; 
    }
};
*/
class Solution {
public:
  string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;  //特殊处理
        int len = s.length();
        string result = "";
        for (int i = 0; i < numRows; i++) {
            int step1 = 2*(numRows-1-i);
            int step2 = 2*i;
            int pos = i;
            result += s[pos];
            while (1) {
                pos += step1;
                if (pos >= len) break;
                if (step1) result += s[pos];  //先算出（n = 1和n= numRows - 2）
                pos += step2;
                if (pos >= len) break;
                if (step2) result += s[pos];  //输出n=0和n = numRows -1行
            }
        }
        return result;
    }
};

class Solution2 {
public:
    string convert(string s, int numRows) {
        string res = "";
        int cycle = 2 * numRows - 2; // zigzag recycle

        if (numRows <= 1 || s.length() <= numRows) 
            return s;
        
        for (int i = 0; i < numRows; i++) {
            //skip a zigzag
            for (int j = i; j < s.length(); j += cycle) {
                res += s[j];// mark first
                int tmp = j + cycle - 2 * i; //this has been calculate first and last line
                if (i != 0 && i != numRows - 1 && tmp < s.length()) 
                    res += s[tmp]; //calculate zigzag char
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    string s("PAYPALISHIRING");
    Solution solution;
    cout << solution.convert(s, 4) << endl;
    return 0;
}