#include <vector>
#include <algorithm>
using std::vector;
using std::swap;
using std::sort;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        backTrace(ret, nums, 0, nums.size() - 1);
        return ret;
    }

    bool isEquel(vector<int>& nums, int l, int r){
        for(int i = l; i < r; i++){
            if(nums[i] == nums[r]) return false;
        }
        return true;
    }
    /**
    * permulate algorithms
    * just watch the [1,2,3] permulate partial result [[1,2,3],[1,3,2],]
    * the origin string is supposed in ordered(maybe need sort first), 
    * the first step about the main frame of permulate is swap the data in 
    * [start] to each other in origin data, the backtrace generat the data 
    * that fixed the each data in index [start]. in same way, repeate to last one.
    * 
    * the tree digram is from root the leaft, but recurse first reache leaft,
    * and backtrace to parent node, and continue to recurse untill finish all work.
    */
    void backTrace(vector<vector<int>>& ret, vector<int>& nums, int start, int depth){
        if(start == depth){
            ret.push_back(nums);
            return;
        }else{
            for(int i = start; i <= depth; i++){
                /**skip the same one
                 *  fixe a data, and add the rest data's permulate, in tree digram, the data in 
                 *  range [start, i] is siblings, if try to get unique permulate, the all data
                 *  in it must be unique
                 **/
                if(!isEquel(nums, start, i)) continue;
                swap(nums[start], nums[i]); //in recurse fixed eache [start, depth] in index start
                backTrace(ret, nums, start + 1, depth);
                swap(nums[start], nums[i]);// after back trace, we need swap to origin data set
            }
        }
    }
};

class Solution {
public:
    //solution from leetcode by genius guy
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        //vector<int> tmp(nums.size());
        vector<int> tmp;
        vector<bool> mark(nums.size(), false);

        sort(nums.begin(), nums.end());
        backTrace(ret, nums, mark, tmp, 0);

        return ret;
    }
    void backTrace(vector<vector<int>>& ret, vector<int>& nums, vector<bool>& mark, vector<int>& tmp, int depth){
        if(nums.size() == depth){
            ret.push_back(tmp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(mark[i] || (i > 0 && nums[i] == nums[i - 1] && !mark[i - 1])) continue;
            mark[i] = true;
            //tmp[depth] = nums[i];
            tmp.push_back(nums[i]);
            backTrace(ret, nums, mark, tmp, depth + 1);
            //to pop the origin data
            tmp.pop_back();
            mark[i] = false;
        }
    }
};