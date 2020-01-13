#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int insertIndext(vector<int> &nums, int target, bool leftMost){
        // returns leftmost (or rightmost) index at which `target` should be
        // inserted in sorted array `nums` via binary search.
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] > target || (leftMost && target == nums[mid])){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int leftIndex = insertIndext(nums, target, true);
         // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.

        if(leftIndex == nums.size() || nums[leftIndex] != target){
            return ret;
        }

        ret[0] = leftIndex;
        ret[1] = insertIndext(nums, target, false) - 1;

        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> nums{5,7,7,8,8,10};
    vector<int> ret = s.searchRange(nums, 9);
    cout <<"[" <<ret[0] << "," << ret[1]<<"]"<<endl;
    return 0;
}