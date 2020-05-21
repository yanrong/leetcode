#include <vector>
#include <algorithm> 
using std::vector;
using std::reverse;
using std::swap;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp, i, k;
        if(nums.size() < 2) return;
        i = nums.size() - 2;
        //find which one is not increase
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }

        if(i >= 0){ // if have one
            int j = nums.size() - 1;
            //fine one greate to nums[i]
            while(j >= 0 && nums[j] <= nums[i]){
                j--;
            }
            //swap it
            swap(nums[i], nums[j]);

        }
        //reverse the whole sequence
        reverse(nums.begin() + i + 1, nums.end());
    }
};