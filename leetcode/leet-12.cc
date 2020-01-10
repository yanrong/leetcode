#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        int r = 1;
        vector<int> v1;
        while(num){
            v1.push_back(num%10 * r);
            num /= 10;
            r *= 10;
        }

        for(vector<int>::reverse_iterator i = v1.rbegin(); i != v1.rend(); i++){
            int temp = *i;
            while(temp){
                switch(temp){
                    case 3000: case 2000: case 1000: temp -= 1000; ret += 'M'; break;
                    case 900: temp -= 900; ret +="CM"; break;
                    case 800: case 700: case 600: case 500: temp -= 500; ret += 'D'; break;
                    case 400: temp -= 400; ret += "CD";break;
                    case 300: case 200: case 100: temp -= 100; ret += 'C'; break;
                    case 90: temp -= 90; ret += "XC"; break;
                    case 80: case 70: case 60: case 50: temp -= 50; ret +='L'; break;
                    case 40: temp -= 40; ret += "XL"; break;
                    case 30: case 20: case 10: temp -= 10; ret +='X'; break;
                    case 9: temp -= 9; ret += "IX"; break;
                    case 8: case 7: case 6: case 5: temp -= 5; ret += 'V'; break;
                    case 4: temp -= 4; ret += "IV"; break;
                    case 3: case 2: case 1: temp -= 1; ret += 'I'; break;
                    default : break; 
                }
            }
        }
        /**cout << "s = " << ret << endl;
        for(int i : v1) cout << i <<endl;*/
        return ret;
    }

    string intToRoman2(int num)
    {
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strScale[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string strRomanNum = "";
        for (int i = 0; num != 0; ++i)
        {
            while (num >= value[i])
            {
                num -= value[i];
                strRomanNum += strScale[i];
            }
        }
        return strRomanNum;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    cout << s.intToRoman2(1994) << endl;
    return 0;
}