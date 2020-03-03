#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ret;

        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]] = i;
        }

        for(int i =0; i < nums.size(); i++){
            int tt = target - nums[i];
            if(hash.count(tt) && hash[tt] != i){
                ret.push_back(i);
                ret.push_back(hash[tt]);
                break;
            }
        }

        return ret;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for(int i = 0; i < nums.size(); i++){
            if(hash.count(target - nums[i])){
                return {i, hash[target - nums[i]]}; //construct from an array
            }

            hash[nums[i]] = i;
        }
    }
};