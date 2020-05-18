#include <algorithm>
using std::max;
using std::abs;
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
    //solution 1 original , but too much redundancy temporary data
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        int leftHeight = getDepth(root->left);
        int rightHeight = getDepth(root->right);
        //this is important, for the balance tree, the root node is balance
        //and respectively the left and right child is balance 
        return abs(leftHeight - rightHeight) <= 1 && 
        isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getDepth(TreeNode* tree){
        if(tree == nullptr){
            return 0;
        }
        return max(getDepth(tree->left), getDepth(tree->right)) + 1;
    }
};


//solution 2, LeetCode Official solution
class Solution {
private:
    // Return whether or not the tree at root is balanced while also storing
    // the tree's height in a reference variable. 
    bool isBalancedTreeHelper(TreeNode* root, int& height) {
        // An empty tree is balanced and has height = -1
        if (root == NULL) {
            height = -1;
            return true;
        }

        // Check subtrees to see if they are balanced. If they are, check if the 
        // current node is also balanced using the heights obtained from the 
        // recursive calls.
        int left, right;
        if (isBalancedTreeHelper(root->left, left)  &&
            isBalancedTreeHelper(root->right, right) &&
            abs(left - right) < 2) {
          // Store the current tree's height
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return isBalancedTreeHelper(root, height);
    }
};