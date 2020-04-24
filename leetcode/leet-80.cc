#include <vector>
#include <unordered_map>
#include <iostream>
using std::vector;
using std::unordered_map;

class Solution {
public:
    //origin solution, the idea may not suitable, ShuiTi tititi
    int removeDuplicates(vector<int>& nums) {
        int ret, len = 0;
        int n = nums.size();
        if(n <= 2) return nums.size();
        
        unordered_map<int, int>hash;
        for(int i = 0; i < n; i++){
            hash[nums[i]]++;
        }
        
        for(int i = 0; i < nums.size(); ){
            int count = hash[nums[i]];
            if(count <= 2){
                i += count;
            }else{
                int p = i + count;
                i += 2;
                nums.erase(nums.begin() + i, nums.begin() + p);
            }
        }
        return nums.size();
    }
    //genius solution from leetcode
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[i] != nums[len-2]){
                nums[len++] = nums[i];
            }
        }
        //just mark and return the length
        //actually the position from len + 1 to nums.size() is still have the data
        return len;
    }
    //official solution
    int removeDuplicates(vector<int>& nums) {
        int j = 1, count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                count++;
            }else{
                count = 1;
            }
            
            if(count <= 2){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,5,6,6,7,};
    s.removeDuplicates(nums);
    return 0;
}
