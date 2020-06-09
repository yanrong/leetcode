#include <vector>
using std::vector;

class Solution {
public:
    //greed algorithm inspired by leetcode
    int maxProfit(vector<int>& prices) {
        int profits = 0;
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1]){//if the price in ascending
                profits += prices[i] - prices[i - 1];
            }
        }
        return profits;
    }
    //leetcode official solution
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int peak = prices[0], valley= prices[0];
        int profits = 0;
        int size = prices.size();
        while(i < size - 1){
            while(i < size - 1 && prices[i] >= prices[i + 1]){
                i++;
            }
            valley = prices[i];
            while(i < size - 1 && prices[i] <= prices[i + 1]){
                i++;
            }
            peak = prices[i];
            profits += peak - valley;
        }
        return profits;
    }
};