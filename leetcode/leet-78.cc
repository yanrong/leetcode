#include <vector>
using std::vector;

class Solution {
public:
    //inspired by leetcode
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp; // first one is empty
        // i == num.size, a set is the subset of itself
        for(int i = 0; i <= nums.size(); i++){
            //generate the subset length is i
            backTrace(ret, tmp, nums, 0, i);
        }
        return ret;
    }
    
    void backTrace(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int start , int ss){
        //if we get the the 
        if(tmp.size() == ss){
            ret.push_back(tmp);
            return;
        }
        
        for(int i = start; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            //start in next step is i + 1 to avoid to duplicate select data in the set
            backTrace(ret, tmp, nums, i + 1, ss);
            tmp.pop_back();
        }
    }
    
    //another genius solution from the Internet
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp; // first one is empty
        //start from position 0 
        backTrace(ret, nums, tmp, 0);

        return ret;
    }
    void backTrace(vector<vector<int>>& ret, vector<int>& nums, vector<int>& tmp, int start ){
        //from the empty set, and expand based on the former set, until the set nums's itself
        //at the beginning of step, record the current set  
        ret.push_back(tmp);
        for(int i = start; i < nums.size(); i++){
            //from start to end of nums, add the nums[i] to the former sets
            tmp.push_back(nums[i]);
            //pick the next position to back trace
            backTrace(ret, nums, tmp, i + 1);
            tmp.pop_back();
        }
    }
    
    //official solution
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret, newSubset;
        vector<int> tmp;
        //first ,add the empty set to result
        ret.push_back(vector<int>());
        //result [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
        for(int num : nums){
            newSubset.clear(); // init the temporay sub-set
            for(auto curr : ret){
                //expand based on the former result
                tmp = curr;
                tmp.push_back(num); // append the current data to each set in sub-set 
                newSubset.push_back(tmp);
            }
            
            for(auto curr : newSubset){
                //store the sub set in ret
                ret.push_back(curr);
            }
        }
        return ret;
    }
};