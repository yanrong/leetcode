#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> rows;
    vector<int> hills;
    vector<int> dales;

    int N;
    int counter;
    
    bool isNotUnderAttack(int row, int col){
        /* diagonal number dales row + col = const(this like y = x + b)
        * hill diagonal(reverse diagonal) (alike y = -x + b)
        * because the each of diagonal row + col or hill diagonal row - col
        * is a const, so we can check the diagonal valid in a time 
        * record which column is valid in the row
        */
        int res = rows[col] + hills[row - col + 2 * N] + dales[row + col];
        return res == 0 ? true : false;
    }
    
    void placeQueue(int row, int col){
        rows[col] = 1; // indicate row at index column is valid
        hills[row - col + 2 * N] =  1; // "hill" diagonals valid
        dales[row + col] = 1; //"dale" diagonals valid
    }
    
    void removeQueue(int row, int col){
        rows[col] = 0;
        hills[row - col + 2 * N] =  0;
        dales[row + col] = 0;
    }

    void backTrace(int row){
        for(int col = 0; col < N; col++){
            if(isNotUnderAttack(row, col)){ // is constraints is valid
                placeQueue(row, col); // place the Queue in this position
                // if n queues are already placed
                if(row + 1 == N){
                    counter++;
                }else{ 
                    backTrace(row + 1); // otherwise, trace to next row
                }
                removeQueue(row, col); // trace back or filed, restore the origin data
            }
        }
    }
    
    int totalNQueens(int n) {
        N = n;
        counter = 0;
        rows = vector<int>(n);
        //hill diagonal's most length is double of diagonal,in worst case row reach the max and col in min
        hills = vector<int>(4 * n - 1);
        dales = vector<int>(2 * n - 1);//the most length of diagonal is double of side length 
        
        backTrace(0);
        return counter;
    }
};