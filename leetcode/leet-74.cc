#include <vector>
using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if( m == 0) return false;
        int n = matrix[0].size();
        
        int left = 0, right = m * n -1 ,pivot ,tmp;
        //binary search, classic algorithm 
        while(left <= right){
            pivot = (left + right) / 2;
            //pivot / n determin which row, privot % n determin whic col
            tmp = matrix[pivot / n][ pivot % n];
            if(target == tmp) return true;
            else{
                if(target > tmp){
                    left = pivot + 1;
                }else{
                    right = pivot - 1;
                }
            }    
        }
        return false;
    }
    
    //solution from genius offer
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        
        while(row < m && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }else{
                //the matrix in row and col all in ascending
                //compare the target with the [row] and [col]
                if(matrix[row][col] > target){
                    col--;
                }else{
                    row++;
                }
            }
        }
        return false;
    }
};