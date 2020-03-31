#include <unordered_set>
#include <vector>
#include <algorithm>
using std::swap;
using std::vector;
using std::unordered_set;

class Solution {
public:
    //genius solution, bu not O(n)
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> result(nums.begin(), nums.end());
        int res;
        
        for(res = 1; res <= nums.size(); res++){
            if(!result.count(res)) return res;
        }
        return res;
    }
    //from other excellent solution
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        /**
         * as before algorithms, we take the index of array and data to build a datastruct
         * key - value, as we define nums[i] = i + 1, so num[0] = 1, nums[1] = 2. 
         * if nums[i] in [1, n], check if the num[i] is equal i + 1, so the statment
         * nums[nums[i] - 1] != nums[i] indicate whether need exchange them in correct place
         **/
        for(int i = 0; i < n; i++){
            if(nums[i] == i + 1) continue;
            while(nums[i] > 0 &&  nums[i] < n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // finally, search the whole array and if num[i] != i + 1, that is solution answer
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) return i + 1;
        }
        //otherwise, the nums.size() + 1 is correctly answer
        return n + 1;
    }

    //official solution
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int contains = 0;

        if( n == 1) return 2;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                contains++;
                break;
            }
        }

        if(contains == 0) return 1;
        // 用 1 替换负数，0， 和大于 n 的数
        // 在转换以后，nums 只会包含正数
        for(int i = 0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        // 使用索引和数字符号作为检查器
        // 例如，如果 nums[1] 是负数表示在数组中出现了数字 `1`
        // 如果 nums[2] 是正数 表示数字 2 没有出现
        for(int i = 0; i < n; i++){
            int a = abs(nums[i]);
            // 如果发现了一个数字 a - 改变第 a 个元素的符号
            // 注意重复元素只需操作一次
            if(a == n){
                nums[0] = -abs(nums[0]);
            }else{
                nums[a] = -abs(nums[a]);
            }
        }
        // 现在第一个正数的下标,  就是第一个缺失的数
        for(int i = 1; i < n; i++){
            if(nums[i] > 0) return i;
        }
        if(nums[0] > 0) return n;
        
        return n + 1;
    }
};