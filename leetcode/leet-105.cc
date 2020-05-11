#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }

        int i = 0;
        for(int i = inStart; i <= inEnd; i++){
            if(preorder[preStart] == inorder[i]){
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[preStart]);
        root->left = helper(preorder, preStart + 1, preStart + i - inStart, inorder, inStart, i - 1);
        root->right = helper(preorder, preStart + i - inStart + 1, preEnd, inorder, i + 1, inEnd);

        return root;
    }
};