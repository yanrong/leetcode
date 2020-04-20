#include <vector>
using std::vector;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ret;
        vector<int> permulate(m);
        for(int i = 1; i <= m; i++){
            permulate[i - 1] = i;
        }
        
        for(int i = 0; i < queries.size(); i++){
            int k = queries[i];
            
            for(int i = 0; i < m; i++){
                if(k == permulate[i]){
                    ret.push_back(i);
                    
                    for(int l = i ; i > 0; i--){
                        permulate[i] = permulate[i - 1];
                    }
                    permulate[0] = k;
                }
            }
        }
        return ret;
    }
};