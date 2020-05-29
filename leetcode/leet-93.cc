#include <vector>
#include <string>
using std::string;
using std::vector;
using std::min;
using std::stoi;
using std::to_string;

class Solution {
public:
    //solution 1 from the Internet
    /*A ip address is consist of 3 field data separated by dots and each field 
    **is a string with length is 3, So the solution is place the 3 dots in the string 
    **and  enumulate the all possible sub-string which value in valid range
    */
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.length() < 4 || s.length() > 12) return ret;
        backTrace(ret, s , "", 3);//three dots
        return ret;
    }

    void backTrace(vector<string>& ret, string s, string tmp, int dot){
        if(dot == -1 && s.empty()){
            //if the 3 dots has been place in the string s in correctly, record the result
            ret.push_back(tmp);
            return;
        }

        for(int i = 1; i <= min(3, (int)s.size()); i++){
            //try possible length sub string
            string ip = s.substr(0, i);
            //get the rest of string
            string rest = s.substr(i);
            //the rest part not enough to place the dots, break
            if(rest.size() < dot) break;
            //to avoid 01, 01 string to int will be 1, invalid
            //if the field length greater 1, it now allowed start with 0
            if(ip.size() > 1 && ip[0] == '0') continue;
            if(stoi(ip) <= 255 && stoi(ip) >= 0){
                if(dot > 0){//if there have one or more dots, continue to trace
                    backTrace(ret, rest, tmp + ip + '.', dot - 1);
                }else{// we reache to finished work
                    backTrace(ret, rest, tmp + ip, dot - 1);
                }
            }
        }
    }

    //solution 2
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 0, "", res);
        return res;
    }
    void helper(string s, int n, string out, vector<string>& res) {
        if (n == 4) {
            if (s.empty()) res.push_back(out);
        } else {
            for (int k = 1; k < 4; ++k) {
                if (s.size() < k) break;
                int val = atoi(s.substr(0, k).c_str());
                if (val > 255 || k != std::to_string(val).size()) continue;
                helper(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), res);
            }
        }
    }

    //Solution 3
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 1; a < 4; ++a) 
        for (int b = 1; b < 4; ++b) 
        for (int c = 1; c < 4; ++c) 
        for (int d = 1; d < 4; ++d) 
            if (a + b + c + d == s.size()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a + b, c));
                int D = stoi(s.substr(a + b + c, d));
                if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                    string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                    if (t.size() == s.size() + 3) res.push_back(t);
                }
            }
        return res;
    }

    //solution 4
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size() > 12)
            return ret;
        for(int i = 0; i < s.size(); i ++)
        {// [0, i]
            for(int j = i+1; j < s.size(); j ++)
            {// [i+1, j]
                for(int k = j+1; k < s.size()-1; k ++)
                {// [j+1, k], [k+1, s.size()-1]
                    string ip1 = s.substr(0, i+1);
                    string ip2 = s.substr(i+1, j-i);
                    string ip3 = s.substr(j+1, k-j);
                    string ip4 = s.substr(k+1);
                    if(check(ip1) && check(ip2) && check(ip3) && check(ip4))
                    {
                        string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
                        ret.push_back(ip);
                    }
                }
            }
        }
        return ret;
    }
    bool check(string ip)
    {
        int value = stoi(ip);
        if(ip[0] == '0'){
            return (ip.size() == 1);
        }else{
            if(value <= 255)
                return true;
            else
                return false;
        }
    }
};