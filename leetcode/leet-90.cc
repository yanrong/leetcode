#include <vector>
using std::vector;

class Solution {
public:
    //origin solution , inspire by leetcode 78
    /********************Solution 1************************/
    void backTrace(vector<vector<int>>& ret, vector<int>& nums, vector<int>& tmp, int start){
        ret.push_back(tmp);
        for(int i = start; i < nums.size(); i++){
            //if the same with previous one, skip
            if(i > start && nums[i] == nums[i - 1]) continue;
            //record
            tmp.push_back(nums[i]);
            //pick the next position to back trace
            backTrace(ret, nums, tmp, i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret, newSubset;
        vector<int> tmp;
        //sort the data
        sort(nums.begin(), nums.end());
        //back trace
        backTrace(ret, nums, tmp, 0);
        return ret;
    }

    /********************Solution 2************************/
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> out;

        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, out, res);

        return res;
    }
    void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res) {
        res.push_back(out);
        for (int i = pos; i < nums.size(); ++i) {
            out.push_back(nums[i]);
            getSubsets(nums, i + 1, out, res);
            out.pop_back();
            //skip the same data
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }

    /************solution 3 Iterator from Internet cnblog****************/
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        sort(nums.begin(), nums.end());

        int size = 1, last = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (last != nums[i]) {
                last = nums[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};