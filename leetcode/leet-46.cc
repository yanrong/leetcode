#include <vector>
#include <unordered_set>
using std::unordered_set;
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
    * the origin string is supposed in ordered(maybe need sort first), 
    * the first step about the main frame of permulate is swap the data in 
    * [start] to each other in origin data, the backtrace generat the data 
    * that fixed the each data in index [start]. in same way, repeat to last one.
    * 
    * the tree digram is from root the leaf, but recurse first reach leaf,
    * and backtrace to parent node, and continue to recurse until finish all work.
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

class Solution {
public:
    //solution from leetcode by genius gay
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() == 0) return ret;
        unordered_set<int> iset;
        vector<int> tmp;
        backTrace(ret, nums, tmp, iset, 0);

        return ret;
    }
    void backTrace(vector<vector<int>>& ret, vector<int>& nums, vector<int>& tmp, unordered_set<int>& used, int depth){
        if(depth == nums.size()){
            ret.push_back(tmp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used.count(i) == 0){//trim the duplicate data
                used.insert(i);
                tmp.push_back(nums[i]);
                backTrace(ret, nums, tmp, used, depth + 1);
                tmp.pop_back();
                used.erase(i);
            }
        }
    }
};