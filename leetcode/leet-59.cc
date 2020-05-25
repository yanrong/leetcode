#include <vector>
using std::vector;

class Solution {
public:
    //half original, derive from leetcode official
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        if(n < 1) return ret; 
        //the direction in each sprawl
        /* left to right,        up to down,       right to left,        down to up
        **     |                       |                  |                 |
        ** add col(increase) add row(increase)    add col(decrease)   add row(decrease)  
        */
        vector<int> dr{0, 1, 0, -1};
        vector<int> dc{1, 0, -1, 0};
        int r = 0, c = 0, di = 0; // init data
        //mark if the [row. col] has been visited
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        //from 1 to n*n
        for(int i = 1; i <= n * n; i++){
            ret[r][c] = i;
            seen[r][c] = true; // if visited, mark it
            //update the row and col,
            int cr = r + dr[di];
            int cc = c + dc[di];
            
            if((0 <= cr && cr < n) &&( 0 <= cc && cc < n) && !seen[cr][cc]){
                //row and col is valid and the data is not visited,
                r = cr; //sustain row and col increase or decrease in a direction
                c = cc;
            }else{
                //otherwise, update the direction
                di = (di + 1) % 4;
                //the further position is based on the current, accumulate all
                r += dr[di];
                c += dc[di];
            }
        }
        return ret;
    }
};