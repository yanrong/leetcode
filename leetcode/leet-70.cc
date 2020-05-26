class Solution {
public:
    //fibonacci array original solution
    int climbStairs(int n) {
        long long p, l, t;
        p = 1, l = 1;
        for(int i = 1 ; i < n; i++){
            t = l;
            l += p;
            p = t;
        }
        return l;
    }
};