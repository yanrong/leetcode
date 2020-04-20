#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;

class Solution {
public:
    string entityParser(string text) {
        map<string, char> html{{"&quot;", '"'},{"&apos;", '\''},{"&amp;", '&'},{"&gt;", '>'},{"&lt;", '<'},{"&frasl;", '/'}};
        string ret, tmp;
        int k ,l;
        for(int i = 0; i != text.size(); i++){
            if(text[i] == '&'){
                l = i;
                k = 1;
                while(k < 7 && i != text.size() && text[i] != ';'){
                    k++;
                    i++;
                }
                tmp = text.substr(l, k);
                if(html.count(tmp) == 1){
                    ret.push_back(html[tmp]);
                }else{
                    ret += tmp;
                }
            }else{
                ret.push_back(text[i]);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    string str, ret;
    Solution s;
    str = "and I quote: &quot;...&quotdd";
    ret = s.entityParser(str);
    std::cout<< ret << std::endl;
    return 0;
}
