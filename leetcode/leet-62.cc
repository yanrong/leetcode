#include <vector>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //dp[i][j] indicate steps from start to point (i,j), column row
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            dp[0][i] = 1;
        }
        for(int j = 0; j < n; j++){
            dp[j][0] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }

    int uniquePaths(int m, int n) {
		vector<vector<int>> dp(n, vector<int>(m,1));
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n - 1][m - 1];
	}

    /**
    * 这是一个计算题。机器人向右走 m-1 步，向下走 n-1 步，则总共要走 m+n-2 步。
    * 而对于向右走（或向下走）有 m-1 种（或 n-1 种）走法，因此结果为 C(n+m-2, m-1) 
    * 或者 C(n+m-2, n-1) 种
    * C(m+n-2, m-1) or C(m+n-2, n-1)
    * C(N, M) = N!/(M!*(N-M)!)
    **/

    //---------------------------------------------------------------------
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        long long res = 1;
        //combination A{m,n}
        for(int i = max(m-1,n-1) + 1 ; i <= m+n-2; i++) {
            res = res*i;
        }
        //less one in {m,n} A{1,min{m,n}}
        for(int i = 1; i <= min(m-1,n-1); i++){
            res /= i;
        }
        return res;
    }
};