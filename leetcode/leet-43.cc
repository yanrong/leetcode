#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    //chinese traditional arithmetic algo
    string multiply(string num1, string num2) {
        string ret = "", temp = "";
        int carry, subCarry;
        long long t;
        
        if(num1.size() < num2.size()) {
            swap(num1, num2);
        }
        if(num2 == "0") return "0";
        for(int i = num2.size() - 1; i >= 0; i--){
            temp = ""; carry = 0; t = 0;
            for(int j = num1.size() - 1; j >= 0; j--){
                t = (num2[i] - '0') * (num1[j] - '0') + carry;
                temp = to_string(t % 10) + temp ;
                carry = t / 10;
            }
            if(carry) temp = to_string(carry) + temp;

            for(int k = num2.size() - 1; k > i; k--){
                temp += "0";
            }
            
            if(ret.size() == 0){
                ret = temp;
            }else{
                subCarry = 0;
                for(int m = ret.size() - 1, n = temp.size() - 1; m >= 0 || n >= 0; m--, n--){
                        t = ((m < 0 ? '0' : ret[m]) - '0') + (temp[n] - '0') + subCarry;
                        temp[n] = t % 10 + '0';
                        subCarry = t / 10;
                }
                
                if(subCarry){
                    temp = to_string(subCarry) + temp;
                }
            }
            ret = temp;
        }
        return ret;
    }

    //other solution provide by leetcode
    /**
    * each time select two number multiply and get result, if the index of two number in string
    * is i and j, the result in a row array is i + j + 1; the index may be greater than 10, we
    * just store the number in i + j and i + j + i.
    **/
    string multiply(string num1, string num2) {
        vector<int> result(num1.size() + num2.size() + 1, 0);
        string ret;
        int t1, t2, temp;
        bool flag = true;
        if (num1 == "0" || num2 == "0") return "0";
        
        for (int i = num1.size() - 1; i >= 0; i--) {
            t1 = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; j--) {
                t2 = num2[j] - '0';
                //each time , add the number in i + j + 1 to current result 
                temp = result[i + j + 1] + (t1 * t2);
                result[i + j + 1] = temp % 10; // i + j + 1 keep the lsb
                result[i + j] += temp / 10; // i + j keep the msb
            }
        }
        
        for (int i = 0; i < result.size() - 1; i++) {
            if (flag && result[i] == 0) continue; // skip the zero before the first valid number
            flag = false;
            ret.push_back(result[i] + '0');
        }
        return ret;
    }
    //other solution in same way
    string multiply(string num1, string num2) {
        string r;
        bool flag = true;
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> result(num1.size() + num2.size() + 1, 0);
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                //first step, just calculate the whole multiply result
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //now from the end to start
        for (int i = result.size() - 1; i > 0; i--) {
            if (result[i] < 10) continue; //if there is no need to calculate carry, skip it
            result[i - 1] += result[i] / 10; //add the MSB
            result[i] %= 10; // get carry integer by mod LSB
        }
        
        for (int i = 0; i < result.size() - 1; i++) {
            if (flag && result[i] == 0) continue;
            flag = false;
            r.push_back(result[i] + '0');
        }
        return r;
    }
};