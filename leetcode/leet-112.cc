#include <stack>
using std::stack;

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
    //solution 1 original solution, it seems like official solution,definitely original solution
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        return isEqual(root, 0, sum);
    }
    bool isEqual(TreeNode* root, int target, int sum){
        int flag =false;
        target += root->val;
        if(root->right == nullptr && root->left == nullptr){
            if(target == sum) {
                return true;
            }
        }
        
        if(root->left != nullptr){
            flag =  flag || isEqual(root->left, target, sum);
        }
        if(root->right != nullptr){
            flag =  flag || isEqual(root->right, target, sum);
        }
        return flag;
    }
    //official solution 2, genius
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return false;
        }
        
        sum -= root->val;
        if(root->right == nullptr && root->left == nullptr){
            return sum == 0;
        }
        
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
    //leetcode official solution 3
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        
        stack<TreeNode*> nodeSt;
        stack<int> sumSt;
        
        nodeSt.push(root);
        sumSt.push(sum - root->val);
        TreeNode *node;
        int currSum;
        
        while(!nodeSt.empty()){
            node = nodeSt.top();
            currSum = sumSt.top();
            nodeSt.pop();
            sumSt.pop();
            if(node->left == nullptr && node->right == nullptr && currSum == 0){
                return true;
            }
            if(node->left != nullptr){
                nodeSt.push(node->left);
                sumSt.push(currSum - node->left->val);
            }
            if(node->right != nullptr){
                nodeSt.push(node->right);
                sumSt.push(currSum - node->right->val);
            }
        }
        
        return false;
    }
};