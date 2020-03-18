#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int in = INT_MAX, out = 0;

        for(int i = 0; i < prices.size(); i++){
            if(in > prices[i] ){
                in = prices[i];
            }else if(prices[i] - in > out){
                out = prices[i] - out;
            }
        }

        return out;
    }
};