#include <vector>
#include <stack>
using std::stack;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    /*******************Solution 1************************/
    //this only suit for the matrix size is row x col 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();

        vector<int> height(col + 1, 0);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                height[j] = (matrix[i][j] == '0') ? 0 : (1 + height[j]);
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& height){
        int ret = 0;
        stack<int> st;
        for(int i = 0; i < height.size(); i++){
            if(st.empty() || height[st.top()] <= height[i]){
                st.push(i);
            }else {
                int top = st.top();
                st.pop();
                
                ret = max(ret, height[top] * (st.empty() ? i :  i - 1 - st.top()));
                //why i--, in the circle loop, the position i always increment 1 when finish
                //this loop, but we need the i suspend at this position, so i-- and i++ make
                //the i is suspending at pop
                i--;
            }
        }
        return ret;
    }
    /*******************Solution 2************************/
    //DP (monster DP) from leetcode official
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int maxArea = 0, row = matrix.size(), col = matrix[0].size();
        //the max width in matrix[i][j], from the left to right
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == '1'){
                    //if in border dp[i][j] = 1, else add the row's width before it
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j];

                    for(int k = i; k >= 0; k--){
                        //the area is depend on the minimun vertical width
                        width = min(width, dp[k][j]);
                        //i - k + 1 is the height at the matrix[i] 
                        maxArea = max(maxArea,  width * (i - k + 1));
                    }
                }
            }
        }
        return maxArea;
    }

    /*******************Solution 3************************/
    //Official solution provided by leetcode
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        /**
        * left and right record left border and right border at matrix[i][j] which the data
        * in left to right all is '1', 
        * */
        vector<int> height(n, 0), left(n, 0), right(n, n);
        int maxArea = 0;

        for(int i = 0; i < m; i++){
            int cur_left = 0, cur_right = n;
            //update height
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){ 
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            //update left
            for(int j = 0; j < n; j++){
                // left reach to as far as possbile, after we have been process the previous row
                // data, the left should be choice the max one(because the area is depend on minimun one)
                // in this way right[j] - left[j] will be the minmum one
                if(matrix[i][j] == '1'){
                    left[j] = max(cur_left, left[j]);
                }else{
                    left[j] = 0;
                    cur_left = j + 1;//from left tor right record the first non '0' postion
                }
            } 
            //update right
            for(int j = n - 1; j >= 0; j--){
                //right always choice the minimun one, in order to get maximun value in right[j] - left[j]
                if(matrix[i][j] == '1'){
                    right[j] = min(cur_right, right[j]);
                }else{
                    right[j] = n;
                    cur_right = j; //from right to left, record the first '1' postion
                }
            } 
            //update area
            for(int j = 0; j < n; j++){
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};

//other solution
class Solution {
public:
    //this is more flexible
    /*******************Solution************************/
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> height;

        for(int i = 0; i < matrix.size(); i++){
            height.resize(matrix[i].size());
            for(int j = 0; j < matrix[i].size(); j++){
                //in this solution, we take each row as a layer,
                //build them all as a rectangle
                height[j] = (matrix[i][j] == '0') ? 0 : (1 + height[j]);
            }
            //calculate the each build rectangle area
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& height){
        int ret = 0;
        stack<int> st;
        height.push_back(0); // for stop at the last data
        for(int i = 0; i < height.size(); i++){
            if(st.empty() || height[st.top()] <= height[i]){
                st.push(i);
            }else {
                int top = st.top();
                st.pop();
                
                ret = max(ret, height[top] * (st.empty() ? i :  i - 1 - st.top()));
                //why i--, in the circle loop, the position i always increment 1 when finish
                //this loop, but we need the i suspend at this position, so i-- and i++ make
                //the i is suspending at pop
                i--;
            }
        }
        return ret;
    }
    /*******************Solution************************/
    //solution from Internet genius
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n + 1);

        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j < n + 1; ++j) {
                if (j < n) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                }
                while (!s.empty() && height[s.top()] >= height[j]) {
                    int cur = s.top(); s.pop();
                    res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
                }
                s.push(j);
            }
        }
        return res;
    }
    /*******************Solution************************/
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int maxArea = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);

        for(int i = 0; i < m; i++){
            int cur_left = 0, cur_right = n;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    //add the height
                    height[j] = height[j] + 1;
                    
                    left[j] = max(left[j], cur_left);
                }else{
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            //calculate each layer
            for(int j = n -1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    
                    right[j] = min(right[j], cur_right);
                }else{
                    right[j] = n;
                    cur_left = j;
                }
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};