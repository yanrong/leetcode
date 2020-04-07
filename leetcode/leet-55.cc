#include <vector>
using std::vector;
using std::max;

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