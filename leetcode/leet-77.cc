#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    //solution 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp;

        backTrace(ret, tmp, 1, n, k);
        return ret;
    }

    void backTrace(vector<vector<int>>& ret, vector<int>& tmp, int start, int n, int k){
        if(tmp.size() == k){
            ret.push_back(tmp);
            return;
        }

        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            //next recurse start position is i + 1, rathan start + 1, 
            //each step we need to choice the unique number
            backTrace(ret, tmp, i + 1, n, k);
            tmp.pop_back();
        }
    }

    //official solution
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> nums;
        int j = 0;
        for(int i = 1; i < k + 1; i++){
            nums.push_back(i);
        }
        nums.push_back(n + 1);

        while(j < k){
            // add current combination
            ret.push_back(vector<int>(nums.begin(), nums.begin() + k));
            j = 0;
            // increase first nums[j] by one
            // if nums[j] + 1 != nums[j + 1]
            while((j < k) && (nums[j + 1] == nums[j] + 1)){
                nums[j] = j + 1;
                j++;
            }
            nums[j] += 1;
        }

        return ret;
    }
};