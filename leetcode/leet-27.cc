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
        return nums.size();
    }
    //official solution
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
    /*if the list contains a few element that is equal val, now we should take other strategy. 
    **if nums[i] is equal val, comparing it to last one and release it, decrese array length
    **if the nums[n-1] should be removed, don't worry it will be checked in next time,
    ** For reason we take this is the former solution shift the array from right to left to many times.
    ** so to avoid worst situation, from end to start compare rather than from start.
    **/
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n - 1];
                n--;
            }else{
                i++;
            }
        }

        return n;
    }
};

int main(int argc, const char** argv) {
    vector<int> vec{0};
    Solution s;
    int ret = s.removeElement(vec, 0);
    cout <<ret <<endl;
    return 0;
}