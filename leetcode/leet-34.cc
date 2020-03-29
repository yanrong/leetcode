#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        int left, right, mid ,pos = -1;

        if(nums.size() < 1) return ret;
        left = 0; right = nums.size() - 1;

        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                pos = mid;
                break;
            }
            if(nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if(pos == -1) return ret;
        //expand to left, and reach the left most position
        for(int i = pos; i >= 0 && nums[i] == target; i--){
            ret[0] = i;
        }
        //expand to the right, 
        for(int j = pos; j <= nums.size() - 1 && nums[j] == target; j++){
            ret[1] = j;
        }
        
        return ret;
    }
    
    /*
    * official solution
    */
    int insertIndext(vector<int> &nums, int target, bool leftMost){
        // returns leftmost (or rightmost) index at which `target` should be
        // inserted in sorted array `nums` via binary search.
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            int mid = (left + right) / 2;
            //if we has been find target, we should to search more until to left is equal to right
            // and return the left range, leftMost control which part should be search
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
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        // find the index of the leftmost appearance of `target`.
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                ret[0] = i;
                break;
            }
        }
        // if the last loop did not find any index, then there is no valid range
        // and we return [-1, -1].
        if(ret[0] == -1){
            return ret;
        }
        // find the index of the rightmost appearance of `target` (by reverse
        // iteration). it is guaranteed to appear.
        for(int j = nums.size() - 1; j >= 0; j++){
            if(nums[j] == target){
                ret[1] = j;
                break;
            }
        }
        
        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> nums{5,7,7,8,8,10};
    vector<int> ret = s.searchRange(nums, 10);
    cout <<"[" <<ret[0] << "," << ret[1]<<"]"<<endl;
    return 0;
}