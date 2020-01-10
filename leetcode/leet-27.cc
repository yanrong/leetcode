#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                nums[j] = nums[i];
            }else{
                nums[j++] = nums[i];
            }
        }
        
        nums.erase(nums.begin() + j, nums.end());
        for(auto cc : nums) cout << cc << " ";cout <<endl;
        return nums.size();
    }
};

int main(int argc, const char** argv) {
    vector<int> vec{0};
    Solution s;
    int ret = s.removeElement(vec, 0);
    cout <<ret <<endl;
    return 0;
}