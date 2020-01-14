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
        //recuse from begin
        recuseSudoku(board, rows, cols, boxes, 0, 0);
    }

    bool recuseSudoku(vector<vector<char>>& board, bool (*rows)[10], bool (*cols)[10], bool (*boxes)[10], int r, int c)    {
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
                    if(recuseSudoku(board, rows, cols, boxes, r, c + 1)){
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
            return recuseSudoku(board, rows, cols, boxes, r, c + 1);
        }
        return false;
    }
};