#include <string>
using std::string;

class Solution {
public:
    //original solution
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

    //original solution
    string addBinary(string a, string b) {
        int a1, b1, s, tc, c = 0;
        char ch;
        if(a.length() < b.length()) swap(a, b);
        int la = a.length() - 1, lb = b.length() - 1;
        
        for(int i = la, j = lb; i >= 0 || j >= 0; i--, j--){
            a1 = (i < 0) ? 0 : a[i] - '0';
            b1 = (j < 0) ? 0 : b[j] - '0';

            s = a1 ^ b1;
            if(s == 1){
                //is XOR is 1, two data is different
                //calculate the carry, in this step, we must take considerate the carray which will cause a new carry
                c = (a1 & c) + (b1 & c);
                //if there a carry, nothing left, just zero 0, else the before carry cause a new carry
                ch = (c ? 0 : 1) + '0';
            }else{
                //if XOR is 0, a and b both is 1 or 0, if both is 0, no carry, the result is equal to the before carry
                //if both is 1, it produce a carry, the result still is equal to carry,
                ch = c + '0' ;
                c = a1 ? 1 : 0;
            }

            a[i] = ch;
        }
        //carry is exit in MSB, add it
        if(c) a.insert(a.begin(), c + '0');

        return a;
    }
};