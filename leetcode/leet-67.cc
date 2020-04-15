#include <string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int a1, b1, s, c = 0;
        int la = a.length(), lb = b.length();
        
        for(int i = la, j = lb; i >= 0 || j >= 0; i--, j--){
            a1 = (i < 0) ? 0 : a[i] - '0';
            b1 = (j < 0) ? 0 : b[j] - '0';
            s = a1 + b1 + c;
            ret.insert(ret.begin(), s % 2 + '0');
            c = s % 2;
        }

        return ret;
    }


    string addBinary(string a, string b) {
        string ret;
        int a1, b1, s, tc, c = 0;
        char ch;
        int la = a.length(), lb = b.length();
        
        for(int i = la, j = lb; i >= 0 || j >= 0; i--, j--){
            a1 = (i < 0) ? 0 : a[i] - '0';
            b1 = (j < 0) ? 0 : b[j] - '0';
            s = a1 ^ b1;
            if(s == 1){
                c = (a1 & c) + (b1 & c);
                ch = (c ? 0 : 1) - '0';
            }else{
                ch = c + '0' ;
                c = a1 ? 1 : 0;
            }
            ret.insert(ret.begin(), ch);
        }

        return ret;
    }
};