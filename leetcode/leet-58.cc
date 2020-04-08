#include <string>
using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        char gap = ' ';
        int counter = 0;
        bool blankSpace = true;
        for(string::reverse_iterator i = s.rbegin() ; i != s.rend(); i++){
            if(*i == gap && blankSpace){
                counter = 0;
                continue;
            }
            blankSpace = false;
            if(*i == gap) break; 
            counter++;
        }
        return counter;
    }
};