#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    //original solution
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        backTrace(ret, nums, 0, nums.size() - 1);
        return ret;
    }
    /**
    * permulate algorithms
    * just watch the [1,2,3] permulate partial result [[1,2,3],[1,3,2],]
    * the origin string is supposed in ordered, the first step about the main frame 
    * of permulate is swap the first one to each other in origin data(include itself,
    * in this situation, it same as origin one),after this operation, the backtrace 
    * generat each result's first element will be with each element in origin data set.
    * repeat the process until the last one
    */
    void backTrace(vector<vector<int>>& ret, vector<int>& nums, int start, int depth){
        if(start == depth){
            ret.push_back(nums);
            return;
        }else{
            for(int i = start; i <= depth; i++){
                swap(nums[start], nums[i]);
                backTrace(ret, nums, start + 1, depth);
                swap(nums[start], nums[i]);// after back trace, we need swap to origin data set
            }
        }
    }
};