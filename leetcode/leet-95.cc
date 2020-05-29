#include <vector>
#include <stack>
using std::stack;
using std::vector;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    //solution from leetcode official
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode*>();
        }
        return generateAllTrees(1, n);
    }
    //Catalan number
    vector<TreeNode*>&  generateAllTrees(int start, int end){
        vector<TreeNode*> ret;
        if(start > end){
            ret.push_back(nullptr);
            return ret;
        }
        
        //pick up a root from 0 to n 
        for(int i = start; i <= end; i++){
            // all possible left subtrees if i is choosen to be a root
            vector<TreeNode*> leftTree = generateAllTrees(start, i - 1);
            // all possible right subtrees if i is choosen to be a root
            vector<TreeNode*> rightTree = generateAllTrees(i + 1, end);
            // connect left and right trees to the root i
            for(auto l : leftTree){
                for(auto r : rightTree){
                    TreeNode* currentNode = new TreeNode(i);
                    currentNode->left = l;
                    currentNode->right = r;
                    ret.push_back(currentNode);
                }
            }
        }
        return ret;
    }
};