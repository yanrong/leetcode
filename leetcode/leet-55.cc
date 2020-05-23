#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int len = nums.size(), prevJump, maxJump = 0 ,start = 0, end = 1, step;
        
        if(len <= 1) return true;
        // from 0 the len - 1
        while(end < len){
            maxJump = 0;
            for(int j = start; j < end; j++){
                if(maxJump < j + nums[j]){
                    maxJump = j + nums[j];
                    step = j;
                }
            }
            if(maxJump >= len - 1) return true;
            if(maxJump == prevJump) break;
            prevJump = maxJump;

            start = step;
            end = maxJump + 1;
        }
        return false;
    }

    bool canJump(vector<int>& nums){
        int end = 0;
        int maxPos = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 1; i++){
            //num[i] + i is reached max distance ,get the greatest one in this range
            maxPos = max(nums[i] + i, maxPos);
            if(maxPos >= n - 1) return true;
            if (i == end) {//if reach the end
                if(end == maxPos && maxPos < n - 1) break;
                end = maxPos; // record the next end; 
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums){
        int maxlen = 0; // 当前能跳到的最远下标
        for(int i=0; i<nums.size(); ++i){
            if(i>maxlen) return false; // 当前遍历的下标超过了之前能跳到的最远下标处
            maxlen = nums[i]+i > maxlen ? nums[i]+i : maxlen; // 在当前节点更新maxlen
            if(maxlen>=nums.size()) return true;
        }
        return true;
    }
    //genius
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};

//official solution by leetcode
class Solution {
public:
//----------------------------------------------------------------------
    //我们模拟从第一个位置跳到最后位置的所有方案。从第一个位置开始，模拟所有可以跳到的位置，
    //然后从当前位置重复上述操作，当没有办法继续跳的时候
    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(0, nums);
    }
    
    bool canJumpFromPosition(int position, vector<int>& nums){
        if(position == nums.size() - 1) {
            return true;
        }
        
        int furthestJump = min(position + nums[position],  (int)nums.size() - 1);
        //FAST in some situation,only recurse if postion jump length is great than current postion
        //for(int nextPosition = furthestJump; nextPosition > position; nextPosition--)
        //in position jump max range, recurse
        for(int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++){
            if(canJumpFromPosition(nextPosition, nums)){
                return true;
            }
        }
        return false;
    }
    //----------------------------------------------------------------------
    // 自顶向下的动态规划可以理解成回溯法的一种优化。我们发现当一个坐标已经被确定为好 / 坏之后，
    // 结果就不会改变了，这意味着我们可以记录这个结果，每次不用重新计算
    enum Index {GOOD, BAD, UNKOWN};
    vector<Index> memo;
    bool canJumpFromPosition(int position, vector<int>& nums, vector<Index>& memo){
        
        if(memo[position] != UNKOWN){
            return memo[position] == GOOD ? true : false;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for(int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++){
            if(canJumpFromPosition(nextPosition, nums)){
                memo[position] = GOOD;
                return true;
            }
        }
        memo[position] = BAD;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size(), UNKOWN);
        
        memo[memo.size() - 1] = GOOD;
        return canJumpFromPosition(00, nums, memo);
    }
    //----------------------------------------------------------------------
    //数组中的每个元素，假设为 i，需要搜索右边相邻的 nums[i] 个元素查找是否有 GOOD
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size(), UNKOWN);
        memo[memo.size() - 1] = GOOD;
        
        for(int i = nums.size() - 2; i >= 0; i--){
            int furthestJump = min(i + nums[i], (int)nums.size() - 1);
            for(int j = i + 1; j < furthestJump; j++){
                if(memo[j] == GOOD){
                    memo[i] = GOOD;
                }
            }
        }
        return memo[0] == GOOD;
    }
    
    //----------------------------------------------------------------------
    /**
    * 从某个位置出发，我们只需要找到第一个标记为 GOOD 的坐标（由跳出循环的条件可得），
    * 也就是说找到最左边的那个坐标。如果我们用一个单独的变量来记录最左边的 GOOD 位置，
    * 我们就可以避免搜索整个数组，进而可以省略整个 memo 数组。
    *
    * 从右向左迭代，对于每个节点我们检查是否存在一步跳跃可以到达 GOOD 的位置
    * （currPosition + nums[currPosition] >= leftmostGoodIndex）。如果可以到达，
    * 当前位置也标记为 GOOD ，同时，这个位置将成为新的最左边的 GOOD 位置，
    * 一直重复到数组的开头，如果第一个坐标标记为 GOOD 意味着可以从第一个位置跳到最后的位置。
    **/
    //greedy strategy
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i + nums[i] >= lastPos){
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};