#include <vector>
#include<algorithm>
using std::vector;
using std::pow;
/**
** 二进制码转换成二进制格雷码，其方法是二进制码的最高位不变，其余位与其前一位做异或运算。
** 如二进制码0010
** 第4位0与第3位1异或的1
** 第3位1与第2位0异或的1
** 第2位0与第1位0异或的0
** 第1位保持不变，任然为0
** 故其对应的二进制格雷码位0011
** 对于整数i，求其对应的格雷码，可使用上述方法，i的格雷码为i^(i>>1) 
** 每一位与前一位做异或运算就等价于i与i右移一位的结果做异或运算。
**/
class Solution {
public:
    //genius solution
    vector<int> grayCode(int n) {
        vector<int> list;
        int N = 1 << n;
        for(int i = 0; i < N; i++){
            list.push_back(i ^ (i >> 1));
        }
        return list;
    }
    //solution 2
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        int suffix = 1;
        for(int i = 0; i < n; i++){
            for(int j = ret.size() - 1; j >= 0; j--){
                ret.push_back(suffix + ret[j]);
            }
            //the way generate the gay code is that add set the MSB of each
            //data to 1, so suffix shift to left a bit(is equal to multiply 2)
            suffix <<= 1;
        }
        return ret;
    }
    
    //recurese from the Internet
    void dfs(vector<int>& ans, int cur, int n){
        if(n == 0) {
            ans.push_back(0); 
            return;
        }//只有一位格雷，特别处理
        if(cur > n) return;
        if(cur == 1){
            ans.push_back(0);
            ans.push_back(1);
            dfs(ans, cur + 1, n);
        }else{
            int len = ans.size();//循环前确定ans的长度，在循环中，ans的长度是变化的
            for(int j = len - 1; j >= 0; j--){//from last one to first
                ans.push_back(ans[j] + pow(2, cur - 1)); 
            }
            dfs(ans, cur + 1, n);
        }
    }
    vector<int> grayCode(int n) {
        vector<int> ans;
        dfs(ans, 1, n);
        return ans;
    }
};