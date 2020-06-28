#include <climits>
#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX;
        int secondBuy = INT_MAX;
        int firstProfit = 0, secondProfit = 0;

        for(auto p : prices){
            firstBuy = min(firstBuy, p); //get the lowest price to buy
            //calculate the current profits, get max profit compare to before
            firstProfit = max(firstProfit, p - firstBuy);
            //compare the second times buy price to current price plus previous profits ,get the lowest price (min one)
            secondBuy = min(secondBuy, p - firstProfit);
            //get the totaly max profits
            secondProfit = max(secondProfit, p - secondBuy);
        }

        return secondProfit;
    }
    //derive from leetcode official genius
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        //dp[i][j][k] represent the ith day, j times transaction, k if have the stock
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
        //the init condtion ,we assume that buy in first transcation day
        dp[0][1][1] = -prices[0];
        dp[0][2][1] = -prices[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= 2; ++j) {
                //in the j times transaction, sell out the all stock, compare the previous max profits, 
                //to sum that add the current price to it 
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                //if you hold the stock, the largest profit need plus the current prices
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
        //get the max profit
        return dp[n-1][2][0];   
    }
};