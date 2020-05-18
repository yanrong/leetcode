#include <unordered_map>
#include <vector>
using std::unordered_map;
using std::vector;

class Solution {
public:
    //solution 1
    //very simple original solution, two slow
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret(2);
        
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if((nums[i] + nums[j] ) == target){
                    ret.push_back(i);
                    ret.push_back(j);
                    break;
                }
            }
        }
        return ret;
    }
    //official solution 2
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ret;

        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int tt = target - nums[i];
            if(hash.count(tt) && hash[tt] != i){
                ret.push_back(i);
                ret.push_back(hash[tt]);
                break;
            }
        }

        return ret;
    }
    //official solution 3
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