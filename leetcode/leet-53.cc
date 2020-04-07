#include <vector>
#include<climits>

using std::max;
using std::vector;

class Solution {
public:
    //greedy algorithms
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], tmp = nums[0];
        //at beginning suppose the max sum is num[0]
        for(int i = 1; i < nums.size(); i++){
            //from index i to last one the sub-array is increase 
            if(nums[i] < tmp + nums[i]){
                tmp = tmp + nums[i]; //add the sum 
            }else{ //otherwise move the max position to current one
                tmp = nums[i];
            }
            
            if(sum < tmp){//if the sum is less the sum in before
                sum = tmp; //update the sum
            }
        }
        return sum;
    }
    //official solution
    //--------------------------------------------------------------------
    //greedy algorithms
    //every step. just choose the max one, if this is not max. skip to next
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], temp = nums[0];
        for(int i = 0; i < nums.size(); i++){
            temp = max(nums[i], temp + nums[i]);
            sum =  max(sum, temp);
        }
        return sum;
    }
    
    //divide and conquer
    int crossSum(vector<int>& nums, int left, int right, int pivot){
        if(left == right) return nums[left];
        
        int leftSubSum = INT_MIN;
        int rightSubSum = INT_MIN;
        int currSum = 0;
        //get the left part sum
        for(int i = pivot; i > left - 1; i--){
            currSum += nums[i];
            leftSubSum = max(leftSubSum, currSum);
        }
        //right part sum
        currSum = 0;
        for(int i = pivot + 1; i < right + 1; i++){
            currSum += nums[i];
            rightSubSum = max(rightSubSum, currSum);
        }
        //total sum
        return leftSubSum + rightSubSum;
    }
    
    int helper(vector<int>& nums, int left, int right){
        if (left == right) return nums[left];
        //select a pivotal
        int pivot = (left + right) / 2;
        //left part of max sum 
        int leftSum = helper(nums, left, pivot);
        //right part of max sum 
        int rightSum = helper(nums, pivot + 1, right);
        //the sum of left part of pivot and right part of pivot
        int cross_sum = crossSum(nums, left, right, pivot);
        return max(max(leftSum, rightSum), cross_sum);
    }
    
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    /*
    * 在整个数组或在固定大小的滑动窗口中找到总和或最大值或最小值的问题可以通过动态规划（DP）在线性时间内解决。
    * 有两种标准 DP 方法适用于数组：
    * 常数空间，沿数组移动并在原数组修改。
    * 线性空间，首先沿 left->right 方向移动，然后再沿 right->left 方向移动。 合并结果。
    */
    //dp programming(Kadane algorithms)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0];
        //dp programming, move from left to last one and update the data
        for(int i = 1; i < n; i++){
            //if data is positive, it must be in increase phase
            if(nums[i - 1] > 0) nums[i] += nums[i - 1];
            //get the max to maxSum
            maxSum = max(nums[i], maxSum);
        }
        
        return maxSum;
    }
    
    //Kadane algorithms from wikipedia, NOT DP
    //https://en.wikipedia.org/wiki/Maximum_subarray_problem
    int maxSubArray(vector<int>& nums) {
        int maxEndHere = nums[0], maxSoFar = nums[0];
        for(int i = 1; i < nums.size; i++){
            maxEndHere = max(nums[i], maxEndHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndHere);
        }
        
        return maxSoFar;
    }
    
    //provide by the CSDN
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        //dp[i] is the max sum of increase subarray end with nums[i]
        // dp = max(nums[i],  dp[i - 1] + nums[i])
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(nums[i] , dp[i - 1] + nums[i]);
        }
        
        for(int i = 1; i < nums.size(); i++){
            if(sum < dp[i]){
                sum = dp[i];
            }
        }
        return sum;
    }
    //---------------------------------------------------------------------
};