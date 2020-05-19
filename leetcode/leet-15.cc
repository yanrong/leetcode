#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) return ret;
        //sort the array
        sort(nums.begin(), nums.end(), less<int>());
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;//if this element is greater 0, as an ascend array, it's impossible that sum is equal with 0
            if(i != 0 && nums[i] == nums[i - 1]) continue; // same as before, skip it
            int left = i + 1, right = nums.size() - 1;
            int sum = 0 - nums[i];
            while(left < right){
                if(nums[left] + nums[right] == sum){
                    ret.push_back({nums[i], nums[left], nums[right]});
                    //while (left < right && nums[left++] == nums[left]);//skip same
					while (left < right && nums[left] == nums[left + 1]){//skip same
                        left++;
                    }
                    //while (left < right && nums[right--] == nums[right]);//skip same
					while (left < right && nums[right] == nums[right - 1]){//skip same
                        right--;
                    }
                    left++; right--;
                }else if(nums[left] + nums[right] < sum){
                    //while (left < right && nums[left++] == nums[left]);// move to greater
					left++;
                }else{
                    //while (left < right && nums[right--] == nums[right]);//move to smaller
					right--;
                }
            }
        }

        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    vector<int> v{-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ret = s.threeSum(v);
    
    for(vector<int> v : ret){
        for(int i : v){
            cout << " "<< i;
        }
        cout <<endl;
    }  
    return 0;
}