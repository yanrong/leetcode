#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int left, mid, right, sum;
        
        if(nums.size() < 4) return ret;
        sort(nums.begin(), nums.end(), less<int>());
        
        for(int i = 0; i < nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                left = j + 1; right = nums.size() - 1;
                while(left < right ){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(target > sum){
                        left++;
                    }else if(target < sum){
                        right--;
                    }else{
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left + 1]) left++;//skip same
                        while (left < right && nums[right] == nums[right -1]) right--;//skiip same
                        
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
    cout <<endl;}
    return 0;
}
