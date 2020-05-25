#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n, 1);
        vector<int> nums;
        string ret; 
        //generate the permulate data
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        // fcatorials[i] is factorial result of (n + 1) = !(n + 1)
        for(int i = 1; i < n; i++){
            factorials[i] = factorials[i - 1] * i;
        }
        // fit k in the interval 0 ... (n! - 1)
        k--;
        // compute factorial representation of k
        for(int i = n; i >= 1; --i){
            //doc-60 more information
            int idx = k / factorials[i - 1];
            k %= factorials[i - 1];
            ret += nums[idx] + '0'; 
            nums.erase(nums.begin() + idx);
        }
    }

    //official solution
    string getPermutation(int n, int k) {
        vector<int> factorials(n);
        vector<int> nums(1, 1);
        factorials[0] = 1;
        string ret;

        for(int i = 1; i < n; ++i){
            //generate factorial system bases 0!, 1!,....(n - 1)!
            factorials[i] = factorials[i - 1] * i;
            //generate nums 1, 2, .... ,n
            nums.push_back(i + 1);
        }
        // fit k in the interval 0 ... (n! - 1)
        k--;
        // compute factorial representation of k
        for(int i = n - 1; i > -1; --i){
            int idx = k / factorials[i];
            k -= idx * factorials[i];

            ret += nums.at(idx) + '0';
            nums.erase(nums.begin() + idx);
        }
        return ret;
    }
};

class Solution{
    //solution from genius jianshu
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";

        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i){
            f[i] = f[i - 1] *i ;
        }
        --k;
        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};