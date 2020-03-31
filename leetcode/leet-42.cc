#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    //calculate each column trap capacity
    int trap(vector<int>& height) {
        int ret = 0;
        int size = height.size();

        for(int i = 1; i < size - 1; i++){
            int maxLeft = 0, maxRight = 0;

            for(int j = i; j >= 0; j++){ //Search the left part for max bar size
                maxLeft = max(maxLeft, height[j]);
            }
            for(int j = i; j < size; j++){//Search the right part for max bar size
                maxRight = max(maxRight, height[j]);
            }
            //how many trap is depend the small sides,and add them all
            //small one puls the current height is the real trap capacity
            ret += min(maxLeft, maxRight) - height[i];
        }
        return ret;
    }
};