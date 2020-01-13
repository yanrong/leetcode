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
                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[box_index][num] = true;
                }
            }
            cout <<endl;
        }
        recuseSudoku(board, rows, cols, boxes, 0, 0);
    }

    bool recuseSudoku(vector<vector<char>>& board, bool (*rows)[10], bool (*cols)[10], bool (*boxes)[10], int r, int c)    {
        if(c == 9){
            c = 0;
            r++;
            if(r == 9) return true;
        }
        int box_index = (r / 3) * 3 + c / 3;
        if(board[r][c] == '.'){
            for(int n = 0; n <= 9; n++){

                bool isValid = !(rows[r][n]  || cols[c][n] || boxes[box_index][n]);
                if(isValid){
                    rows[r][n] = true;
                    cols[c][n] = true;
                    boxes[box_index][n] = true;
                    board[r][c] = (char)('0' + n);
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
            return recuseSudoku(board, rows, cols, boxes, r, c + 1);
        }
        return false;
    }
};