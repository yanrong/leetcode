#include <string>
using std::string;

class Solution {
public:
    //original solution ????
    int lengthOfLastWord(string s) {
        char gap = ' ';
        int counter = 0;
        bool blankSpace = true;
        //from the end to first one
        for(string::reverse_iterator i = s.rbegin(); i != s.rend(); i++){
            if(*i == gap && blankSpace){//trim the blank space at end
                counter = 0;
                continue;
            }
            blankSpace = false;//if non blank space, mark it
            if(*i == gap) break; //if the blank space appear in the middle, break;
            counter++;//if the continus non-blank space, count it
        }
        return counter;
    }
};