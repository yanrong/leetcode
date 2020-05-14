#include <vector>
#include <map>
using std::map;
using std::vector;

class Solution {
public:
    //leetcode official solution
    int numWays(int n, vector<vector<int>>& relation, int k) {
        /* dp[i][j] 表示数组的第 i 轮传递给编号 j 的人的方案数。
        ** y 玩家的所有玩家编号 x1,x2,x3... , 则第 i+1 轮传递信息给编号 y 玩家的递推方程为
        ** dp[i+1][y] = sum(dp[i][x1],dp[i][x2],dp[i][x3]...)，
        ** 其递推形式即
        ** dp[i+1][y] += dp[i][x]
        */
        vector<vector<int>> dp(k + 1, vector<int>(n));
        
        dp[0][0] = 1;
        for(int i = 0; i < k; i++){
            for(auto vec : relation){
                dp[i + 1][vec[1]] += dp[i][vec[0]];
            }
        }
        return dp[k][n - 1];
    }
};

//leetcode genius guy DFS
class Solution {
public:
    int ans = 0;
    int numWays(int n, vector<vector<int>>& relation, int k) {
        for(int i = 0; i < relation.size(); i++){
            //in the beginning start at 0
            if(relation[i][0] == 0)
                dfs(relation, relation[i][1], 1, k, n);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& relation, int start, int step, int k, int n){
        if(step == k){
            if(start == n-1)
                ans++; // if in step k and we reach the n, add counter
            return;
        }
        for(int i = 0; i < relation.size(); i++){
            //from the start, search next one
            if(relation[i][0] == start)
                dfs(relation, relation[i][1], step+1, k, n);
        }
    }
};
