#include <climits>
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
    //inspire by leetcode official solution
    bool isValidBST(TreeNode* root) {
        //if the empty tree, return  true
        if(root == nullptr) return true;
        //at beginning , assume that node value in [-inf, inf]
        return backTrace(root, LONG_MIN, LONG_MAX);
    }
    bool backTrace(TreeNode* root, long long left, long long right){
        if(root == nullptr) return true;
        //if the value is invalid , return false
        if(root->val <= left || root->val >= right) return false;
        //check the left tree, the value range in [-inf, root->val]
        //check the right tree, the valid value range in [root->val, inf]
        return backTrace(root->left, left, root->val) 
            && backTrace(root->right, root->val, right);
    }
    //official solution 2
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long long inorder = (long long)INT_MIN - 1;
        //tree not empty
        while(!st.empty() || root != nullptr){
            //add all left node
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            //get the left most node
            root = st.top();
            st.pop();
            //compare the value, BTS left < root < right, so root->val must less the inorder
            if(root->val <= inorder) return false;
            //bacause we take this node as root , update the inorder
            inorder = root->val;
            //visit the right child
            root = root->right;
        }
        return true;
    }
    //solution 3 from genius guy
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = nullptr;
        return helper(root, pre);
    }
    bool helper(TreeNode* root, TreeNode*& pre){
        if(root == nullptr){
            return true;
        }
        //visit left child
        if(!helper(root->left, pre)) return false;
        //if has previous node, copare the value
        if(pre != nullptr && pre->val >= root->val) return false;
        //get the left child
        pre = root;
        //visit the right child
        return helper(root->right, pre);
    }
};