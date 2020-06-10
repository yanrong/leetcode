#include <climits>
#include <algorithm>
using std::max;
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
    int maxPathSum(TreeNode* root) {
        int maxChild = INT_MIN;
        helper(root, maxChild);
        return maxChild;
    }

    int helper(TreeNode* node, int &maxChild){
        if(node == nullptr){
            return 0;
        }
        //recurese the two child
        int left = helper(node->left, maxChild);
        int right = helper(node->right, maxChild);
        //if the two child is valid maxPath, get the max path
        maxChild = max(maxChild, node->val + max(left, 0) + max(right, 0));
        // for recursion :
        // return the max gain if continue the same path
        return node->val + max(left, right);
    }
};