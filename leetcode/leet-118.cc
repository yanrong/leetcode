#include <vector>
using std::vector;

class Solution {
public:
    //original solution 1
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> tmp;
        //how many line data
        for(int i = 1; i <= numRows; i++){
            tmp.clear();
            tmp.resize(i);
            //first and last data always is 1
            tmp[0] = 1;
            tmp[i - 1] = 1;
            //for a row data, the index from 1 to a before last one 
            for(int j = 1; j < i - 1; j++){
                //ret[i - 2] from the 3rd row, need to calculate the middle data
                tmp[j] = ret[i - 2][j] + ret[i - 2][j - 1];
            }
            ret.push_back(tmp);
        }
        return ret;
    }
    
    //recurse solution Warning OVERTIME
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> tmp;
        for(int i = 1; i <= numRows; i++){
            tmp.clear();
            tmp.resize(i);
            for(int j = 1; j < i + 1; j++){
                tmp[ j - 1] = data(i, j);
            }
            ret.push_back(tmp);
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
    //other solution
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i < numRows; i++){
            vector<int> tmp(i+1, 1);
            for(int j=1; j < i; j++){
                tmp[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(tmp); 
        }
        return res;
    }
};