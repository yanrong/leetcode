#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int left, mid, right, sum;
        
        if(nums.size() < 4) return ret;
        sort(nums.begin(), nums.end(), less<int>());
        // i < size - 3, make sure at least have 3 data
        for(int i = 0; i < nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue; //skil same
            //make sure at least have 2 data
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; //skip same
                //in range [j + 1, size - 1]
                left = j + 1; right = nums.size() - 1;
                while(left < right ){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    //we have been sort the all data
                    if(target > sum){
                        left++; // if the sum is small, move to right
                    }else if(target < sum){
                        right--; // else move to left
                    }else{//the sum is ame with target
                        //record the result
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        //skip the same
                        while (left < right && nums[left] == nums[left + 1]) left++;//skip same
                        while (left < right && nums[right] == nums[right -1]) right--;//skip same
                        //and decrease the range
                        left++; right--;
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v{1, 0, -1, 0, -2, 2};
    vector<vector<int>> ret = s.fourSum(v, 0);
    for(vector<int> v : ret){
        for(int i : v) cout << " " << i;
        cout <<endl;
    }
    return 0;
}
