#include <string>
using std::string;

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1", tmp;
        int count  = 1;
        for(int i = 1; i < n; i++){
            tmp = "";
            for(int j = 0; j < ret.size(); j++){
                count = 1;
                while((j + 1) < ret.size() && ret[j] == ret[j + 1]){
                    count++; j++;
                }
                tmp += to_string(count) + ret[j];
            }
            ret = tmp;
        }

        return  ret;
    }
};