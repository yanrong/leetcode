#include<vector>
using std::vector;

class Solution {
public:
    //AC code, origin
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1, tmp;
        for(int i = n - 1; i >= 0; --i){
            tmp = digits[i] + carry;
            digits[i] = tmp % 10;
            carry = tmp / 10;
            if(!carry) break;
        }
        if(carry) digits.insert(digits.begin(), carry);
        return digits;
    }
};