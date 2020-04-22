#include <vector>
#include <string>
using std::vector;
using std::string;

//solution 1, similar to MAZE
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m < 1) return false;
        int n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //each step start from position (i,j)
                if(backTrace(board, word, visit, direction, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool backTrace(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, vector<vector<int>>& direction, int start, int r, int c){
        if(start == word.size() - 1){
            //if this is last one data, compare it and get result
            return board[r][c] == word.at(start);
        }
        
        if(board[r][c] == word.at(start)){
            visit[r][c] = true; // if position [r][c] is equal
            for(int k = 0; k < 4; k++){//search in four direction
                int nextR = r + direction[k][0];
                int nextC = c + direction[k][1];
                if(nextR < 0 || nextR >= board.size() || nextC < 0 || nextC >= board[0].size()){ 
                    //to avoid out out boundary
                    continue;
                }
                //if not visit, try to search next
                if(visit[nextR][nextC] == false){
                    if(backTrace(board, word, visit, direction, start + 1, nextR, nextC)){
                        return true;
                    }
                }
            }
            //if search failed, backtrace and remark it not visit
            visit[r][c] = false;
        }
        //it the data is no equal ,return false
        return false;
    }
    
    //solution 2
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m < 1) return false;
        int n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //each step start from position (i,j)
                if(backTrace(board, word, visit, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool backTrace(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int start, int r, int c){
        bool ret;
        //because only the data is same, it will to seach next, so start === word.size
        if(start == word.size()){
            return true;
        }
        
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()){ 
            // out out boundary
            return false;
        }
        //if visit and not equal return false
        if(visit[r][c] == true || board[r][c] != word[start]){
            return false;
        }
        visit[r][c] = true;
        //recurse from four direction
        ret = backTrace(board, word, visit, start + 1, r + 1, c) ||
            backTrace(board, word, visit, start + 1, r - 1, c) ||
            backTrace(board, word, visit, start + 1, r, c + 1) ||
            backTrace(board, word, visit, start + 1, r, c - 1);
        
        visit[r][c] = false;
        return ret;
    }
};