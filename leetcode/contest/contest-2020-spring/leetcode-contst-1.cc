#include <vector>
using std::vector;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int count = 0, c;
        
        for(int i = 0; i < coins.size(); i++){
            c = coins[i];
            if(c <= 2){
                count++;
            }else{
                while(c >= 2){
                    c -= 2;
                    count++;
                }
                if(c > 0) count++;
            }
        }
        return count;
    }
};