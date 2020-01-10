#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0, distance = 0, left, right, sum, temp = INT_MAX;
        sort(nums.begin(), nums.end(), less<int>());

        for(int i = 0 ; i < nums.size(); i++){
            left = i + 1; right = nums.size() - 1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];

                if(sum > target){ 
                    distance = abs(target - sum);
                    if(distance < temp) {temp = distance; ret = sum;}
                    right--;
                }else if (sum < target){
                    distance = abs(target - sum);
                    if(distance < temp){temp = distance, ret = sum;}
                    left++;
                }
                else return sum; 
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s;
    vector<int> v{4, -1, -4, 4};
    int ret = s.threeSumClosest(v, 3);
    cout <<"ret "<< ret << endl;
    return 0;
}
