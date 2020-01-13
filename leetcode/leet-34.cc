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
            if(nums[mid] ==  target){
                pos = mid;
                break;
            }
            if(nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        cout <<"pos " << pos<<endl;
        if(pos == -1) return ret;

        for(int i = pos; i >= 0 && nums[i] == target; i--){
            ret[0] = i;
        }
        
        for(int j = pos; j <= nums.size() - 1 && nums[j] == target; j++){
            ret[1] = j;
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