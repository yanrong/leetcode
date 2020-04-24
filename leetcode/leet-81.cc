#include <vector>
using std::vector;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        int left = 0, right = n - 1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            //if the [left, mid] range is ascending
            if(nums[mid] > nums[left]){
                //it the key in this range, move to right to left
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    //else move the left to right
                    left = mid + 1;
                }
            }else if (nums[mid] < nums[left]){
                //else if the [left, mid] range seems not in ascending
                //first judge the [mid, right]
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1; // if the target in [mid, range], move left to right
                }else{
                    //else move the right to left
                    right  = mid -1;
                }
            }else{
                //if the nums[mid] == nums[left], increment left, to skip the duplication data
                left++;
            }
        }

        return false;
    }
};