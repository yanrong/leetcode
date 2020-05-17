#include <vector>
using std::vector;

class Solution {
public:
    //solution 1 original
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1);
        for(int i = 0; i <= rowIndex; i++){
            //the first and last one set 1
            ret[i] = 1;
            ret[0] = 1;
            //from the end to start
            for(int j = i; j > 1; j--){
                ret[j - 1] = ret[j - 1] + ret[j - 2];
            }
        }
        return ret;
    }
    
    //fuck , overtime
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        for(int i = 1; i < rowIndex; i++){
            ret.push_back(data(rowIndex, i));
        }
        return ret;
    }
    //x ----row , y --- column
    int data(int x, int y){
        //if the col = 1 or row == col(last one data)
        if(y == 1 || x == y){
            return 1; //filled with 1
        }
        //recurese calculate the data
        return data(x - 1, y) + data(x - 1, y - 1);
    }
};