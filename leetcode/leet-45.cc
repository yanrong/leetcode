#include <vector>
#include <iostream>
#include <algorithm>
using std::max;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    //original soultion
    int jump(vector<int>& nums) {
        int len = nums.size(), jump ,counter = 0, temp = 0, step, i = 0;
        if(nums.size() <= 1) return 0;
        jump = nums[0];
        // from 0 the len -1
        while(i < len){
            step = 0; temp = jump;
            //search the whole string in [i + 1, jump]
            for(int j = 1; j <= jump && (i + j < len); j++){
                if(i + jump >= len -1){ //if the index add jump great string length, skip the whole string
                    break;
                }
                //else find the max one in the jump range
                //i is current valid index, j + num[i+j] update j in range jump and add it's jump value
                if((i + j + nums[i + j]) > temp) {
                    temp = i + j + nums[i + j];
                    step = j; 
                }
            }
            //this step update the index i, each time we assign a zero to var step,
            //so if step is zero, that meas jump in i is grate most, update i with it' jump value
            //otherwise , we get best one and remember the distance from i to it, so add it up 
            i += (step == 0) ? jump : step;
            counter++;
            if(i >= len - 1) break; //this is very import, must test it
            jump =  nums[i] ; // update the current jump value
        }
        return counter;
    }
    
    //from other solution in leetcode ikaruga
//greedy algorithms
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int start = 0;
        int end = 1;//至少每次可以跳到下一个数
        while (end < nums.size())
        {
            int maxPos = 0;
            for (int i = start; i < end; i++)
            {
                // 能跳到最远的距离
                maxPos = max(maxPos, i + nums[i]);
            }
            start = end;      // 下一次起跳点范围开始的格子
            end = maxPos + 1; // 下一次起跳点范围结束的格子
            ans++;            // 跳跃次数
        }
        return ans;
    }
    
    int jump(vector<int>& nums)
    {
        int ans = 0;
        int end = 0;
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            //num[i] + i is reached max distance ,get the greatest one in this range
            maxPos = max(nums[i] + i, maxPos);
            if (i == end) //if reach the end
            {
                end = maxPos; // record the next end; 
                ans++; // finish a jump, add counter
            }
        }
        return ans;
    }
};

int main(int argc, const char** argv) {
    int ret;
    Solution s;
    vector<int> nums{2,1};
    ret = s.jump(nums);
    cout <<"ret = " <<ret << endl;
    return 0;
}