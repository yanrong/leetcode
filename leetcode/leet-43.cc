#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    //chinese traditional arithmetic algo
    string multiply(string num1, string num2) {
        string ret = "", temp = "";
        int carray, subCarray;
        long long t;
        
        if(num1.size() < num2.size()) {
            swap(num1, num2);
        }
        if(num2 == "0") return "0";
        for(int i = num2.size() - 1; i >= 0; i--){
            temp = ""; carray = 0; t = 0;
            for(int j = num1.size() - 1; j >= 0; j--){
                t = (num2[i] - '0') * (num1[j] - '0') + carray;
                temp = to_string(t % 10) + temp ;
                carray = t / 10;
            }
            if(carray) temp = to_string(carray) + temp;

            for(int k = num2.size() - 1; k > i; k--){
                temp += "0";
            }
            
            if(ret.size() == 0){
                ret = temp;
            }else{
                subCarray = 0;
                for(int m = ret.size() - 1, n = temp.size() - 1; m >= 0 || n >= 0; m--, n--){
                        t = ((m < 0 ? '0' : ret[m]) - '0') + (temp[n] - '0') + subCarray;
                        temp[n] = t % 10 + '0';
                        subCarray = t / 10;
                }
                
                if(subCarray){
                    temp = to_string(subCarray) + temp;
                }
            }
            ret = temp;
        }
        return ret;
    }

    //other solution provide by leetcode
    string multiply(string num1, string num2) {
        vector<int> result(num1.size() + num2.size() + 1, 0);
        string ret = "";
        if (num1=="0" || num2=="0") return "0";
        
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                result[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = result.size() - 1; i > 0; i--) {
            if (result[i] < 10) continue;
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
        
        bool zero = true;
        for (int i = 0; i < result.size() - 1; i++) {
            if (zero && result[i] == 0) continue;
            zero = false;
            ret.push_back(result[i]+'0');
        }
        return ret;
    }
};