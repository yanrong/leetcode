#include <string>
#include <vector>
using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> result;
        
        backTrace(board, 0, result);
        
        return result;
    }
    
    void backTrace(vector<vector<char>> &board, int row,  vector<vector<string>>& result){
        int n = board.size();
        //check row by row until last row
        for(int col = 0; col != n; col++){
            //set the position is Q(queue)
            board[row][col] = 'Q';
            if(check(board, row, col) == true){ // if this position is valid
                if(row == n - 1){ // check if is the last row
                    getResult(board, result); // if we reach last row, finish a times work
                }else{
                    backTrace(board, row + 1, result); //we still not finished the work, move to next row
                }
            }
            // if this place is not valid, restore it to origin data
            // otherwise, if we finished a work, the recurse will trace back, in this condition, we also
            // need to restore the board to  origin data
            board[row][col] = '.'; 
        }
    }
    
    bool check(vector<vector<char>> &board, int row, int col){
        if (row == 0) return true;
        //check the each col 
        for(int i = 0; i != row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        //check the each row
        for(int j = 0; j != col; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        //reverse diagonal index is row - 1 and col - 1, and check it
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        //diagonal index is row -1 and col + 1, row in decrease and col in increase
        for(int i = row - 1, j = col + 1; i >= 0 && j != board.size() ; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    void getResult(vector<vector<char>> &board, vector<vector<string>>& result)
    {
        int row, col;
        vector<string> tv;
        string tmp;

        for (row = 0; row != board.size(); ++row) {
            tmp.assign("");
            for (col = 0; col != board.size(); ++col) {
                tmp.push_back(board[row][col]);//store the all data in a string
            }
            tv.push_back(tmp);// store a result
        }
        result.push_back(tv);
    }
};

//official solution
//对于所有的主对角线有 行号 + 列号 = 常数，对于所有的次对角线有 行号 - 列号 = 常数. ??
class Solution {
public:
    vector<int> rows;
    vector<int> hills;
    vector<int> dales;
    vector<vector<string>> output;
    vector<int> queues;
    int N;
    
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
        queues[row] = col; //record the exactly column is valid in this row if the constraints is valid
        rows[col] = 1; // indicate row at index column is valid
        hills[row - col + 2 * N] =  1; // "hill" diagonals valid
        dales[row + col] = 1; //"dale" diagonals valid
    }
    
    void removeQueue(int row, int col){
        queues[row] = 0; //remove the mark
        rows[col] = 0;
        hills[row - col + 2 * N] =  0;
        dales[row + col] = 0;
    }
    
    void addSolution(){
        vector<string> solution;
        for(int i = 0; i < N; i++){
            // queue recoder in this row, which one is valid, each row has one a valid place
            int col = queues[i];
            string tmp;
            for(int j = 0; j < col; j++){
                tmp.push_back('.');
            }
            tmp.push_back('Q');
            for(int j = 0; j < N - col - 1; j++){
                tmp.push_back('.');
            }
            solution.push_back(tmp);
        }
        output.push_back(solution);
    }
    
    void backTrace(int row){
        for(int col = 0; col < N; col++){
            if(isNotUnderAttack(row, col)){ // is constraints is valid
                placeQueue(row, col); // place the Queue in this position
                // if n queues are already placed
                if(row + 1 == N){
                    addSolution(); // is we has been search to last row, get a solution
                }else{ 
                    backTrace(row + 1); // otherwise, trace to next row
                }
                removeQueue(row, col); // trace back or filed, restore the origin data
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        rows = vector<int>(n);
        //hill diagonal's most length is double of diagonal,in worst case row reach the max and col in min
        hills = vector<int>(4 * n - 1);
        dales = vector<int>(2 * n - 1);//the most length of diagonal is double of side length 
        queues = vector<int>(n);
        
        backTrace(0);
        return output;
    }
};