#include <vector>
#include <algorithm> 
using std::vector;
using std::reverse;
using std::swap;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int temp, i, k;
        if(nums.size() < 2) return;
        i = nums.size() - 2;
        //find which one is not increase
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }

        if(i >= 0){ // if have one
            int j = nums.size() - 1;
            //fine one is less or equal it
            while(j >= 0 && nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
            //swap it
            /*
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;*/
        }
        // then reverse sub set from i to last one
        /*k = nums.size() - 1;
        i++;
        while(i < k){
            temp = nums[i];
            nums[i] = nums[k];
            nums[k] =  temp;
            i++; k--;
        }*/
        reverse(nums.begin() + i + 1, nums.end());
    }
};