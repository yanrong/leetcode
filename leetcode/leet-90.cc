#include <vector>
#include <algorithm>
using std::sort;
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
    /*
    *对于上一个处理的数字，然后判定当前的数字和上面的是否相同，若不同，则循环还是从0到当前子集的个数，若相同，
    *则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复
    */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());
        int k = 0, j;
        for (int i = 0; i < nums.size(); ++i) {
            int size = res.size();
            j = 0;
            if(i > 0 && nums[i - 1] == nums[i]){
                j = size - k;
            }
            k = 0; // k record how many data has been add to
            for ( ; j < size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
                k++;
            }
        }
        return res;
    }
    //zhihu
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());
        int dupCount, size;
        for(int i = 0; i < nums.size(); i++){
            dupCount = 0;
            //判断当前是否是重复数字，并且记录重复的次数
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]){
                dupCount++;
                i++;
            }
            size = res.size();
             //遍历之前几个结果的每个解
            for(int j = 0; j < size; j++){
                vector<int> list = res[j];
                for(int t = 0; t <= dupCount; t++){
                    //每次在上次的结果中多加 1 个重复数字
                    list.push_back(nums[i]);
                    res.push_back(list);
                }
            }   
        }
        return res;
    }
};