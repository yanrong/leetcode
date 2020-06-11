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
    //leetcode official solution
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
        int left = max(helper(node->left, maxChild), 0);
        int right = max(helper(node->right, maxChild), 0);
        //try to take two child as valid Path, get the max path
        maxChild = max(maxChild, node->val + left + right);
        // for any node, you can only choices a greater child to further path
        return node->val + max(left, right);
    }
};