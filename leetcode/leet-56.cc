#include <vector>
#include<algorithm>
using std::vector;
using std::sort;
using std::max;

class Solution {
public:
    //origin solution
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ret;
        vector<int> t1;
        if(n <= 1) return intervals;

        sort(intervals.begin(), intervals.end());
        ret.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            t1 = intervals[i];
            
            if(ret[ret.size() - 1][1] < intervals[i][0]){
                ret.push_back(intervals[i]);
            }else{
                ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], intervals[i][1]);
            }
            
        }
        return ret;
    }

    //official solution
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());

        for(auto interval : intervals){
            if(ret.empty() || ret[ret.size() - 1][1] < interval[0]){
                ret.push_back(interval);
            }else{
                ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], interval[1]);
            }
        }
        return ret;
    }
};
