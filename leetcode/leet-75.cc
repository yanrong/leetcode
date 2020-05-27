#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    /**half origin solution**/
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        for(int i = left; i <= right;){
            if(nums[i] == 0){
                //set the data 0 to left part,
                swap(nums[left], nums[i]);
                left++;
                i++; // this step need to increment index
            }else if(nums[i] == 2){
                //set the 2 to right part,
                //but we need fixed the general index i, because
                //after the swap, nums[i] is 0 or 1, we need rejudge and swap,
                swap(nums[i], nums[right]);
                right--;// decrease the right index
            }else{
                //if the nums[i] is 1, we just skip it, this actually in middle of nums, 
                //it will be placed in correct index in subsequent swap it
                //[1,2,0] test error if not judge 1
                i++;
            }
        }
    }
    //official solution
    /**
    **  初始化0的最右边界：p0 = 0。在整个算法执行过程中 nums[idx < p0] = 0.
    **  初始化2的最左边界 ：p2 = n - 1。在整个算法执行过程中 nums[idx > p2] = 2.
    **  初始化当前考虑的元素序号 ：curr = 0.
    **  While curr <= p2 :
    **  若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。
    **  若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。
    **  若 nums[curr] = 1 ：将指针curr右移。
    **/
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int curr = left;
        
        while(left <= right){
            if(nums[curr] == 0){
                swap(nums[left++], nums[curr++]);
            }else if(nums[curr] == 2){
                swap(nums[curr], nums[right--]);
            }else{
                curr++;
            }
        }
    }
};