#include <iostream>
#include <vector>
#include <map>
using std::map;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    //official solution 1
    bool isValidSudoku(vector<vector<char>>& board) {
        int temp;
        map<int, int> rows[9], columns[9], boxes[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int n = board[i][j] - '1';
                    //box size is 3x3,from left to right and from top to bottom, No.1 to No.8
                    //a row has three box
                    int box_index = (i / 3) * 3 + j / 3;
                    //key - value key store number has been appear, value counter how many times
                    //find the key in the rows[i]
                    if(rows[i].find(n) != rows[i].end()){
                        temp = rows[i][n];//if exist, get the char n times
                    }else{ 
                        temp = 0;//first time, is zero
                    }
                    rows[i][n] = temp + 1;//record the char n times

                    if(columns[j].find(n) != columns[j].end()){ 
                        temp = columns[j][n];
                    }else{
                        temp = 0;
                    }
                    columns[j][n] = temp + 1;

                    if(boxes[box_index].find(n) != boxes[box_index].end()) {
                        temp = boxes[box_index][n];
                    }else{
                        temp = 0;
                    }
                    boxes[box_index][n] = temp + 1;
                    //the valid sudo only need each char is unique
                    if(rows[i].count(n) > 1 || columns[j].count(n) > 1 || boxes[box_index].count(n) > 1){
                        return false;
                    }
                }
            }
        }

        return true;
    }
    //optimal, too slow???
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, int> rows[9], columns[9], boxes[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int n = board[i][j] - '1';
                    //box size is 3x3,from left to right and from top to bottom, No.1 to No.8
                    //a row has three box
                    int box_index = (i / 3) * 3 + j / 3;
                    //key - value key store number has been appear, value counter how many times
                    //find the key has been in the rows[i], invalid board
                    if(rows[i].count(n) > 0){
                        return false;
                    }else{ 
                        rows[i][n] = 1; //else add it to row
                    }

                    if(columns[j].count(n) > 0){ 
                        return false;
                    }else{
                        columns[j][n] = 1;
                    }

                    if(boxes[box_index].count(n) > 0) {
                        return false;
                    }else{
                        boxes[box_index][n] = 1;
                    }
                }
            }
        }

        return true;
    }
};

