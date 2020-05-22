#include <string>
using std::string;
using std::to_string;

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1", tmp;
        int counter;
        for(int i = 1; i < n; i++){
            tmp = ""; counter = 1;//init generated string and same counter;
            for(int j = 1; j < ret.size(); j++){
                if(ret[j - 1] == ret[j]){//if it has same value, add counter
                    counter++;
                }else{//add same number counter to the end;
                    tmp += to_string(counter) + ret[j - 1];
                    counter = 1;
                }
            }
            //generate result + counter + finally one
            ret = tmp + to_string(counter) + ret[ret.size() - 1];
        }
        return ret;
    }
    string countAndSay2(int n) {
        int counter;
        string ret="";
        if(n <= 1) return string("1");
        //boring design
        string tmp = countAndSay2(n - 1);
        counter = 1;
        for(int i = 1; i < tmp.length(); i++){
            if(tmp[i - 1] == tmp[i]){
                counter++;
            }else{
                ret += to_string(counter) + tmp[i - 1];
            }
        }
        ret += to_string(counter) + tmp[tmp.size() - 1];
        
        return ret;
    }
};