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
    
    bool isNumber(string s) {
        int state = 0;
        enum TYPE {INVALID = - 1,SPACE, SIGN, DIGIT, DOT, EXPONENT};
        vector<vector<int>> transfer{
            { 0, 1, 6, 2,-1},
            {-1,-1, 6, 2,-1},
            {-1,-1, 3,-1,-1},
            { 8,-1, 3,-1, 4},
            {-1, 7, 5,-1,-1},
            { 8,-1, 5,-1,-1},
            { 8,-1, 6, 3, 4},
            {-1,-1, 5,-1,-1},
            { 8,-1,-1,-1,-1}};
        
        for(int i = 0; i < s.size(); i++){
            TYPE input = INVALID;
            if(s.at(i) == ' ') input = SPACE;
            else if(s.at(i) == '+' || s.at(i) == '-') input = SIGN;
            else if(isdigit(s.at(i))) input = DIGIT;
            else if(s.at(i) == '.') input = DOT;
            else if(s.at(i) == 'e' || s.at(i) == 'E') input = EXPONENT;
            if(input < 0) return false;
            state = transfer[state][input]; 
            if(state == 0) return false;
        }
        return (state ==4 ||state == 6 ||state == 7 || state == 8);
    }
}; 