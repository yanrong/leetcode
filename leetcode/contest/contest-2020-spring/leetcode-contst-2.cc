#include <vector>
using std::vector;

class Solution {
public:
	//Answer Error
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int m = relation.size();
        int ret = 0, step;
        
        vector<int> t;
        
        for(int i = 1; i < m; i++){
            t = relation[0];
            step = 0;
            if(t[1] == relation[i][0]){
                t = relation[i];
                step++;
                for(int j = 1; j < m && step < k; j++){
                    if(t[1] == relation[j][0]){
                        t = relation[j];
                        step++;
                    }    
                }
            }
            if(step == k -1 &&  t[1] == n - 1){
                ret++;
            }
        }
        
        return ret;
    }
};
