#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::min;
using std::cout;
using std::endl;

class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        if(numRows == 1 || numRows > n) return s;
        
        for(int i = 0; i < numRows; i++){ //calculate each row
            for(int j = 0; i + j < n; j += cycleLen){ // j equal to a cycle zigzag, i + j will skip to next zigzag
                ret += s[i + j]; // each zigzag, add colum char to ret.
                if(i != 0 && i != numRows - 1 && (j + cycleLen - i) < n){ //if row number is not  0 or numRows -1 and
                    /*cycle - i is distance from column char to zigzag char,
                    j start from 0, j + cycle -i is exactly zigzag char place*/
                    ret += s[j + cycleLen - i];
                }
            }
        }
        
        return ret;
    }
    
    string convert1(string s, int numRows) {
        string ret;
        bool goingDown = false;
        int curRow =0;
        vector<string> rows(min(numRows, (int)s.size()));
        
        for(char c : s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == (numRows - 1)) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        for(string row : rows) ret += row;
        
        return ret;
    }

    string convert3(string s, int numRows) {
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