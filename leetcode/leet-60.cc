#include <string>
#include <vector>
using std::vector;
using std::string;
using std::swap;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n, 1);
        vector<int> nums;
        string ret; 

        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        for(int i = 1; i < n; i++){
            factorials[i] = factorials[i - 1] * i;
        }

        k--;
        for(int i = n; i >= 1; --i){
            int idx = k /factorials[i - 1];
            k %= factorials[i - 1];
            ret += nums[idx] + '0'; 
            nums.erase(nums.begin() + idx);
        }
        return ret;
    }
};