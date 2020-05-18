#include <vector>
#include <algorithm>
#include <climits>
using std::vector;
using std::min;

class Solution {
public:
    //solution 1 from leetcode
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //from bottom to top, two dimension array
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                //get the small one to add
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
    //solution 2
    //optimize from the bottom to top
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //a dimension array
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < triangle[i].size(); j++){
                //from 0 to last data, 
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
    //solution 3 from the top to bottom
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), minimun = INT_MAX;

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= triangle[i - 1].size(); j++){
                if(j == 0){//if the last data
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
                }else if (j == i){
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                }else{
                    triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][ j - 1]) + triangle[i][j];
                }
            }
        }
        for(int i = 0; i < triangle[n - 1].size(); i++){
            minimun = min(minimun, triangle[n-1][i]);
        }
        return minimun;
    }
};