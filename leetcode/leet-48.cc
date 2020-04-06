#include <vector>
#include <algorithm>
using std::vector;
using std::swap;
using std::reverse;

class Solution {
public:
    //origin solution, invalid
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        //this is not allowed
        vector<vector<int>> tmp(size, vector<int>(size));
        int start = size - 1;
        for(int i = 0; i < size && start >= 0 ; i++){
            
            for(int j = 0; j < size; j++){
                tmp[j][start - i] = matrix[i][j];
            }
        }
        matrix = tmp;
    }   
    //the solution from leetcode
    //reverse the matrix in diagonal
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0; i <  size; i++){
            for(int j = i; j < size; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < size; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    //reverse the martix in reverse diagonal
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<int> tmp(size);
        //in reverse diagonal j from zero to index before diagonal
        //the [i][j] mirror index is out of j boundary, the total length is size - 1;
        //we also know the index of j, the mirror of j is size -1 - j
        for(int i = 0 ; i < size; i++){
            for(int j = 0; j < size - 1 - i ; j++){
                swap(matrix[i][j], matrix[size - 1 - j][size - 1 - i]);
            }
        }

        for(int i = 0; i < size / 2; i++){
            tmp = matrix[i];
            matrix[i] =  matrix[size - 1 - i];
            matrix[size - 1 - i] =  tmp;
        }
    }
    
    //official solution
    //rotate the four sub matrix in clockwise
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), row, col, x;
        vector<int> tmp(4);
        for(int i = 0; i < n / 2 + n % 2; i++){ //determine search depth
            for(int j = 0; j < n / 2; j++){ // search element in rectangle
                //from index 0,0, record the index of row and col
                row = i;
                col = j;
                //get the data in index [i] in each rectangle 
                for(int k = 0; k < 4; k++){
                    tmp[k] = matrix[row][col];
                    x = row; //switch row and col
                    row = col;
                    // calculate the new col, n - 1 is total size of matrix
                    // x is the row in previous rectangle, the current [row] index is n - 1 - x;
                    col = n - 1 - x; 
                }
                //after all step, [row, col] now back to the start position
                for(int k = 0; k < 4; k++){
                    //reverse the matrix data, revese the tmp, add them to matrix
                    matrix[row][col] = tmp[(k + 3) % 4];
                    //the postion move is same as before
                    x = row;
                    row = col;
                    col = n - 1 - x;
                }
            }
        }
    }
    //take the same policy as before one, reverse the four rectangle in martix
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < (n + 1) / 2; i++){
            for(int j = 0; j < n / 2; j++){
                //reverse-clockwise
                // the first one is [i][j], the next one index is switch row and column, 
                // and calculate the new row [n - 1 - j] the row index alway is n - 1 - col
                int temp = matrix[n - 1 - j][i];
                //second replace withe third data, 
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                //the third replace by previous one
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                //fourth replace with first
                matrix[j][n - 1 - i] = matrix[i][j];
                //assing second to first 
                matrix[i][j] = temp; 
                
                //finished the cycle replace
            }
        }
    }
};