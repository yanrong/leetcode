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
    }

    int helper(TreeNode* node, int &maxChild){
        if(node == nullptr){
            return 0;
        }
        int left = helper(node->left, maxChild);
        int right = helper(node->right, maxChild);
        maxChild = max(maxChild, node->val + max(left, 0) + max(right, 0));
        return max(maxChild, node->val + max(left, right));
    }
};