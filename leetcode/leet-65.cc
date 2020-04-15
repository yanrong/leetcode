#include <vector>
#include <string>
using std::string;
using std::vector;

class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        enum TYPE {INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT};
        vector<vector<int>> transfer{
            {-1,  0,  3,  1,  2, -1,}, 
            {-1,  8, -1,  1,  4,  5,}, 
            {-1, -1, -1,  4, -1, -1,}, 
            {-1, -1, -1,  1,  2, -1,}, 
            {-1,  8, -1,  4, -1,  5,}, 
            {-1, -1,  6,  7, -1, -1,}, 
            {-1, -1, -1,  7, -1, -1,}, 
            {-1,  8, -1,  7, -1, -1,}, 
            {-1,  8, -1, -1, -1, -1,}};
        
        for(int i = 0; i < s.size(); i++){
            TYPE input = INVALID;
            if(s.at(i) == ' ') input = SPACE;
            else if(s.at(i) == '+' || s.at(i) == '-') input = SIGN;
            else if(isdigit(s.at(i))) input = DIGIT;
            else if(s.at(i) == '.') input = DOT;
            else if(s.at(i) == 'e' || s.at(i) == 'E') input = EXPONENT;
            state = transfer[state][input]; 
            if(state == -1) return false;
        }
        return (state == 1 || state == 4 || state == 7 || state == 8);
    }


    bool isNumber(string s)
    {
        enum InputType{
            INVALID, SIGN, DIGIT, DOT, EXPONENT,  
        };
        //trim the space in end and start
        s.erase(0,s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);  

        int transitionTable[][5] = {
            -1,  1, 2,  3, -1, //state0  
            -1, -1, 2,  3, -1, //state1    
            -1, -1, 2,  4,  5, //state2
            -1, -1, 6, -1, -1, //state3
            -1, -1, 4, -1,  5, //state4
            -1,  7, 8, -1, -1, //state5
            -1, -1, 6, -1,  5, //state6
            -1, -1, 8, -1, -1, //state7
            -1, -1, 8, -1, -1, //state8
        };


        int state = 0;
        for(int i = 0; i < s.size(); i++){
            InputType inputType = INVALID;

            if (s[i] == '+' || s[i] == '-')
                inputType = SIGN;
            else if (isdigit(s[i]))
                inputType = DIGIT;
            else if (s[i] == '.')
                inputType = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];
            if (state == -1)
                return false;
        }
        return state == 2 || state == 4 || state == 6 || state == 8;
    }
}; 