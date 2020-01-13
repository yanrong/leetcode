#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size(), mid;

        if(nums.size() < 1) return left;
        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] > target){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //because mid = (left + right) / 2; it has been reached leftmost position
        //left border judge, if target great rightmost, it should insert in [right + 1] 
        if(nums[mid] < target) mid++;
        
        return mid;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> nums{1};
    int ret = s.searchInsert(nums, -10);
    cout <<"ret = " << ret <<endl;
    return 0;
}
