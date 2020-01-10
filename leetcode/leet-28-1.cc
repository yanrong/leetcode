#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        while(i < haystack.length() && j < needle.length()){
            if(haystack[i++] == needle[j++]);
            else{ i -= j - 1; j = 0;}
        }

        return  j == needle.length() ? i - j: -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int ret;
    string s1("mississippi"), s2("issip");
    string s3("cdbcdfcdcdadf"), s4("cdcda");
    ret = s.strStr("", "t");
    cout <<"ret = " << ret << endl;
    return 0;
}
