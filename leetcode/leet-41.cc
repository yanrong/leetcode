#include <unordered_set>
#include <vector>
#include <algorithm>
using std::swap;
using std::vector;
using std::unordered_set;

class Solution {
public:
    //genius solution, bu not O(n)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> result(nums.begin(), nums.end());
        int res;
        
        for(res = 1; res <= nums.size(); res++){
            if(!result.count(res)) return res;
        }
        return res;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 1;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == i + 1) continue;
            while(nums[i] > 0 &&  nums[i] < n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};