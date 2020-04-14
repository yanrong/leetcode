#include<vector>
using std::vector;
using std::min;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //dp[i][j] is min step to index[i,j]
        vector<vector<long>> dp(m, vector<long>(n));
        dp[0][0] = grid[0][0];
        //accumulate the
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for(int i = 1; i < m; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                //get the minimum one
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};