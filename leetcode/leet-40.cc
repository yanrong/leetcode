#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end());
        backTrace(ret, candidates, tmp, 0, target);
        return ret;
    }

    void backTrace(vector<vector<int>>& ret, vector<int>& candidates, vector<int> tmp, int pos, int target){
        if(target == 0){//if get a result, add to ret
            ret.push_back(tmp);
            return;
        }
        //target must be less equal candidates[i]
        for(int i = pos; i < candidates.size() && candidates[i] <= target; i++){
            /*pos start from 0, so if recurse back, we need check if this one is equal
            * to the previous one, i != pos also avoid to overflow in indices i - 1
            */
            if(i != pos && candidates[i] == candidates[i - 1]) continue;
            tmp.push_back(candidates[i]);
            //because unique result, if pick [i] , next recurse should start in next one
            backTrace(ret, candidates, tmp, i + 1, target - candidates[i]);
            //backtrace to parent node 
            tmp.pop_back();
        }
    }
};