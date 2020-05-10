#include <queue>
using std::queue;

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
    //origin solution 1.  inspired by leetcode
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return backTrace(root->left, root->right);
    }
    bool backTrace(TreeNode *left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;
        if(left->val == right->val){
            return backTrace(left->left, right->right) &&
                backTrace(left->right, right->left);
        }else{
            return false;
        }
    }
    
    //leetcode official solution 2
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    bool isMirror(TreeNode *t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false;
        
        return (t1->val == t2->val) && backTrace(t1->left, t2->right) &&
            backTrace(t1->right, t2->left);
    }
    
    //official solution 3
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            if(t1 == nullptr && t2 == nullptr) continue;
            if(t1 == nullptr || t2 == nullptr) return false;
            if(t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};