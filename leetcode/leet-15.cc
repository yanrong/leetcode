#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end(), less<int>());
        /*for(int i : nums) cout << " "<< i;
        cout <<endl;*/
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i != 0 && nums[i] == nums[i - 1]) continue; // same as before, skip it
            int left = i + 1, right = nums.size() - 1;
            int sum = 0 - nums[i];
            while(left < right){
                if(nums[left] + nums[right] == sum){
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left++] == nums[left]);//skip same
                    while (left < right && nums[right--] == nums[right]);//skiip same
                }else if(nums[left] + nums[right] < sum){
                    while (left < right && nums[left++] == nums[left]);// move to greater
                }else{
                    while (left < right && nums[right--] == nums[right]);//move to smaller
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
    //cout << ret.size()<< endl;
    
    return 0;
}