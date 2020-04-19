#include <string>
using std::string;
using std::min;

/* *
 *  each steps, we can operate on a string in three ways DELETE, INSERT, REPLACE
 *  in order to get the result, the operations DELETE A is equal to INSERT B, and
 *  DELETE B is equal to INSERT B, REPLACE a char in A is equal to REPLACE in B
 *  so the algorithm simplification to three steps
 *  INSERT a char in string A
 *  INSERT a char in string B
 *  REPLACE a char in string A
 * */
class Solution {
public:
    //Over time limit
    int minDistance(string word1, string word2) {
        int a, b, c;
    
        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0){
            return word1.length();
        }
        //insert a char in word2
        a = minDistance(word1, word2.substr(0, word2.length() - 1)) + 1;
        //insert a char in word1
        b = minDistance(word2, word1.substr(0, word1.length() - 1)) + 1;
        //repace char in word1 and word2, diacard the loat char, because the recurse in before has
        //calculate this char
        c = minDistance(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() -1));
        //after replace the char int both string, it the last one is no equal, 
        //that indicate need one more step to get result
        if(word1.at(word1.length() - 1) != word2.at(word2.length() - 1)){
            c++;
        }

        return min(min(a, b) ,c);
    }

    int minDistance(string word1, string word2) {
        int l1 = word1.length(); 
        int l2 = word2.length();
        if(l1 == 0 || l2 == 0){
            return l1 + l2;
        }
        //dp[i][j] represent the min edit distance of word1 [0, i) and word2 [0, j)
        int dp[l1 + 1][l2 + 1];
        //empty string match
        for(int i = 0; i <= l1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i <= l2; i++){
            dp[0][i] = i;
        }
        /**
         * INSERT word2 dp[i - 1][j] 
         * INSERT word1 dp[i][j - 1]
         * REPLACE word1 and word2 dp[i - 1][j - 1]
         * **/
        for(int i = 1; i <= l1; i++){
            for(int j = 1; j <= l2; j++){
                int del = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                int replace = dp[i - 1][j - 1];
                if(word1[i - 1] != word2[j - 1]){
                    replace++;
                }
                dp[i][j] = min(del, replace);
            }
        }

        return dp[l1][l2];
    }
};