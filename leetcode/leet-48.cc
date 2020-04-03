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
        //in rever digoanl j from zero to index before digonal
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
};