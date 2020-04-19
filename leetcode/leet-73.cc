#include <vector>
using std::vector;

class Solution {
public:
    //half origin solution
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
    
    //official solution
    void setZeroes(vector<vector<int>>& matrix) {
        int MIN = -100000;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    //mark the col and row first
                    for(int k = 0; k < n; k++){
                        if(matrix[i][k] != 0){
                            matrix[i][k] = MIN;
                        }
                    }
                    for(int k = 0 ; k < m; k++){
                        if(matrix[k][j] != 0){
                            matrix[k][j] = MIN;
                        }
                    }
                }
            }
        }
        //after finish the mark, fill the 0 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == MIN){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    /**
    * 我们可以用每行和每列的第一个元素作为标记，这个标记用来表示这一行或者这一列是否需要赋零。
    * 这意味着对于每个节点不需要访问 M+NM+N 个格子而是只需要对标记点的两个格子赋值。
    * LeetCode
    **/
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            // Since first cell for both first row and first column is the same i.e. matrix[0][0]
            // We can use an additional variable for either the first row/column.
            // For this solution we are using an additional variable for the first column
            // and using matrix[0][0] for the first row.
            if(matrix[i][0] == 0){
                isCol = true;
            }
            
            for(int j = 1; j < n; j++){
                // If an element is zero, we set the first element of the corresponding row and column to 0
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // Iterate over the array once again and using the first row and first column, update the elements.
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        //See if the first row needs to be set to zero as well
        if(matrix[0][0] == 0){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        //See if the first column needs to be set to zero as well
        if(isCol){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};