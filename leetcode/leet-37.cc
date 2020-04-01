#include <vector>
using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //key  valid
        bool rows[9][10] = {false}, cols[9][10] = {false}, boxes[9][10] = {false};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int box_index = (i / 3) * 3 + j / 3;
                    //init evey valid char in board
                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[box_index][num] = true;
                }
            }
        }
        //recurse from begin
        recurseSudoku(board, rows, cols, boxes, 0, 0);
    }

    bool recurseSudoku(vector<vector<char>>& board, bool (*rows)[10], bool (*cols)[10], bool (*boxes)[10], int r, int c)    {
        if(c == 9){ //if we have finish a row(column from 1 to 9 ),
            c = 0;// column back to zero
            r++; // get next row
            if(r == 9) return true; //it all finished return
        }
        int box_index = (r / 3) * 3 + c / 3; // box id
        if(board[r][c] == '.'){
            for(int n = 1; n < 10; n++){ // try number from 1 to 9
                //if number n is valid to add to board
                bool isValid = !(rows[r][n]  || cols[c][n] || boxes[box_index][n]);
                if(isValid){//mark the this unique
                    rows[r][n] = true;
                    cols[c][n] = true;
                    boxes[box_index][n] = true;
                    board[r][c] = (char)('0' + n);
                    //this is important, if board[r][c] = n is valid, try to fixed board[r][c + 1]
                    //because we dispose by a line to anther line by increase column index until reach border
                    //if reach column border(finished a line(row)), r++ get next row
                    //untill all object is done,  return true r = 9 && r = 9 
                    if(recurseSudoku(board, rows, cols, boxes, r, c + 1)){
                        return true;
                    }
                    board[r][c] = '.';
                    rows[r][n] = false;
                    cols[c][n] = false;
                    boxes[box_index][n] = false;
                }
            }
        }else{
            //if board[r][c] is vailid number, try next one in this line(row)
            return recurseSudoku(board, rows, cols, boxes, r, c + 1);
        }
        return false;
    }
};

class Solution {
public:
    bool rows[9][10]={false}, cols[9][10] = {false}, boxes[9][10] = {false};
    bool isSudokuSolved = false;

    void backTrace(vector<vector<char>>& board, int row, int col){
        int idx = (row / 3) * 3 + col / 3;
        if(board[row][col] == '.'){
            for(int i = 1; i < 10; i++){
                //try number 1 - 9 , add it to board if it is valid
                if(!(rows[row][i] || cols[col][i] || boxes[idx][i])){
                    rows[row][i] = cols[col][i] = boxes[idx][i] = true; //mark it
                    board[row][col] = i + '0'; //fill the board
                    //this is important one, dispose next: next char in line(row)
                    //or next row
                    placeNextNumber(board, row, col); 
                    // if sudoku is solved, there is no need to backtrack
                    // since the single unique solution is promised
                    if(!isSudokuSolved){
                        rows[row][i] = cols[col][i] = boxes[idx][i] = false;
                        board[row][col] = '.';
                    }

                }
            }
        }else{//try to dispose next one
            placeNextNumber(board, row, col);
        }
    }

    void placeNextNumber(vector<vector<char>>& board, int row, int col){
        /*
        *   Call backtrack function in recursion
        *   to continue to place numbers
        *   till the moment we have a solution
        */
        // if we're in the last cell
        // that means we have the solution
        if(col == 8 && row == 8){
            isSudokuSolved = true;
        }else{
            //
            if(col == 8){//if we finished a line(row), skip to next row
                backTrace(board, row + 1, 0);
            }else{// if now we in a specify line, try to place next one 
                backTrace(board, row, col + 1);
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        int idx;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                idx = (i / 3) * 3 + j / 3;//box id
                //if number is valid numver, mark it
                if(board[i][j] != '.'){
                    int n = board[i][j] - '0';
                    rows[i][n] = cols[j][n] = boxes[idx][n] = true;
                }
            }
        }
        //trace from first one
        backTrace(board, 0, 0);
    }
};