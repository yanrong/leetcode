#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;

        if(nums.size() < 1) return -1;

        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            
            if(nums[left] <= nums[mid]){ //[left mid] is a ascending
                // if target in this range
                if(target <= nums[mid] && target >= nums[left]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                //else [mid right] is ascending range
                if(target >= nums[mid] && target <= nums[right]){// if target in this range
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};