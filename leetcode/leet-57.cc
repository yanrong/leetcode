#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    //original AC code from Duyanrong 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        vector<int> tmp;

        int n = intervals.size(), i = 0;
        //add the the data that right] is less than newInterval [left
        while(i < n && intervals[i][1] < newInterval[0]){
            ret.push_back(intervals[i++]);
        }
        //if this step has been reach the last one. qucik solve 
        if(i == n) {
            ret.push_back(newInterval);
            return ret;
        }
        //it new one should be insert in before of current data
        if(intervals[i][0] > newInterval[1]) {
            ret.push_back(newInterval);
        }else{//else, interval range are overlapping each other
            ret.push_back(intervals[i]);
            ret[ret.size() - 1][1] = max(newInterval[1], ret[ret.size() - 1][1]);
            ret[ret.size() - 1][0] = min(newInterval[0], ret[ret.size() - 1][0]);
            i++;
        }
        //dispose the rest data, use the same strategy
        while(i < n){
            tmp = intervals[i];
            if(tmp[0] > ret[ret.size() - 1][1]){
                ret.push_back(tmp);
            }else{
                ret[ret.size() - 1][1] = max(tmp[1], ret[ret.size() - 1][1]);
                ret[ret.size() - 1][0] = min(tmp[0], ret[ret.size() - 1][0]);
            }   
            i++;
        }
        return ret;
    }

    //---------------------------------------------------------------------------
    //official solution by leetcode
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int newStart = newInterval[0], newEnd = newInterval[1];
        int idx = 0, n = intervals.size();
        vector<vector<int>> output;
        vector<int> interval(2);

        while(idx < n && newStart > intervals[idx][0]){
            output.push_back(intervals[idx++]);
        }
        // if there is no overlap, just add the interval
        if(output.empty() || output.back()[1] < newStart){
            output.push_back(newInterval);
        }else{
            // if there is an overlap, merge with the last interval
            interval = output.back();
            output.pop_back();
            interval[1] = max(interval[1], newEnd);
            output.push_back(interval);
        }

        //add next intervals, merge the newInterval if needed
        while(idx < n){
            interval = intervals[idx++];
            int start = interval[0], end = interval[1];
            //if there is no overlap, just add an interval
            if(output.back()[1] < start) {
                output.push_back(interval);
            }else{
            //if there is an overlap, merge with the last interval
                interval = output.back();
                output.pop_back();
                interval[1] = max(interval[1], end);
                output.push_back(interval);
            }
        }

        return output;
    }
};