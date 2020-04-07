#include <vector>
using std::vector;

class Solution {
public:
    /*          up 0
    * |--------------------|
    * |   |1 | 2 | 3 | 4|  |        |1 | 1 | 1 | 1|
    * | l |5 | 6 | 7 | 8| r| --->   |1 | 2 | 2 | 1|   
    * | 0 |9 |10 |11 |12| N|        |1 | 2 | 2 | 1|
    * |   |13|14 |15 |16|  |        |1 | 1 | 1 | 1|
    * |--------------------|
    *           down N
    * the result 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int n = matrix.size();
        if(n < 1) return ret;
        
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = n - 1;
        
        while(up <= down && left <= right){
            //from left to right, add a row
            if(up < n){
                for(int i = left; i <= right; i++){
                    ret.push_back(matrix[up][i]);
                }
                up++; // move wall to next row
            }
            //from up to down, rotata 90 degree in clockwise. add column
            if(right >= 0){//from the right
                for(int i = up; i <= down; i++){
                    ret.push_back(matrix[i][right]);
                }
                right--;//move the wall to previous col
            }
            //rotate 90 degree, from left to right, add row
            if(up <= down){
                for(int i = right; i >= left; i--){
                    ret.push_back(matrix[down][i]);
                }
                down--;// move to previous row
            }
            //from down to up
            if(left <= right){
                for(int i = down; i >= up; i--){
                    ret.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ret;
    }

    //official solution
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int n = matrix.size();
        if(n < 1) return ret;
        int R = n, C = matrix[0].size();
        //seen[c][r] mark the data in matrix has been visited, default is invalid 
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        //and index di indicate the directoin of current position
        vector<int> dr{0, 1, 0, -1};
        vector<int> dc{1, 0, -1, 0};
        //init row and col , di = 0 map to dr and dc mean row is static and column move to next one
        int r = 0, c = 0, di = 0;
        for(int i = 0; i < R * C; i++){
            ret.push_back(matrix[r][c]);
            seen[r][c] = true; // if visited, mark is in valid
            int cr = r + dr[di]; // get the next row
            int cc = c + dc[di]; // get next col
            //judge if the row and col is in range and the [r][c] is not visited
            if((0 <= cr && cr < R) && (0 <= cc && cc < C ) && !seen[cr][cc]){
                //update the current row and col
                r = cr; c = cc;
            }else{
                //if out of range
                di = (di + 1) % 4; // calculate the directoin 
                r += dr[di]; //
                c += dc[di]; //update row and col
            }
        }
        return ret;
    }

    //emulate by layer
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) return ret;

        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;

        while(r1 <= r2 && c1 <= c2){
            //from left to right, add a row
            for(int i = c1; i <= c2; i++) ret.push_back(matrix[r1][i]);
            //finish add a row, next col should start [row + 1]
            for(int i = r1 + 1; i <= r2; i++) ret.push_back(matrix[i][c2]);
            //the reverse row and col add is restricted with the former border
            // from right to left, if still have element to be add
            if(r1 < r2 && c1 < c2){
                //add a row, we have finished a col before, the row start index is  [col - 1]
                for(int i = c2 - 1; i > c1; i--) ret.push_back(matrix[r2][i]);
                //add a column
                for(int i = r2; i > r1; i--) ret.push_back(matrix[i][c1]);
            }
            r1++; r2--; //border decrease by step
            c1++, c2--; // 
        }
        return ret;
    }
};