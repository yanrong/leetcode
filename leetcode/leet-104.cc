#include <algorithm>
#include <queue>
using std::queue;
using std::max;
/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**************************DFS***************************/
    //very simple original solution
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    //official solution 
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int left_height = maxDepth(root->left);
            int right_height = maxDepth(root->right);
            return max(left_height, right_height) + 1;
        }
    }

    /**************************BFS***************************/
    //half origin solution
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        TreeNode *tmpNode;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size())
        {
            depth++;
            for(int i = q.size(); i > 0; i--){
                tmpNode = q.front();
                q.pop();
                if(tmpNode->left){
                    q.push(tmpNode->left);
                }
                if(tmpNode->right){
                    q.push(tmpNode->right);
                }
            }
        }
        return depth;
    }
};