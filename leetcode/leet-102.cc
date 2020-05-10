#include <vector>
#include <queue>
using std::queue;
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
    //origin solution 1
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> level;
        queue<TreeNode*> levelTreeNode;
        TreeNode *tmpNode;

        if(root == nullptr) return ret;
        levelTreeNode.push(root); //add the root first
        
        while(!levelTreeNode.empty()){
            //get the current level node number
            int size = levelTreeNode.size();
            for(int i = 0; i < size; i++){
                //get the each node and remove it from the queue head
                tmpNode = levelTreeNode.front();
                levelTreeNode.pop();
                level.push_back(tmpNode->val);//record the value
                //add the left and right child if valid
                if(tmpNode->left != nullptr){
                    levelTreeNode.push(tmpNode->left);
                }
                if(tmpNode->right != nullptr){
                    levelTreeNode.push(tmpNode->right);
                }
            }
            //collection the result
            ret.push_back(level);
            level.clear();
        }
        return ret;
    }
    
    //leetcode official solution 2 recurese
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;
        
        helper(root, ret, 0);
        return ret;
    }
    void helper(TreeNode* node, vector<vector<int>>& ret, int level){
        if(ret.size() == level){
            ret.push_back(vector<int>());
        }
        ret.at(level).push_back(node->val);
        if(node->left != nullptr){
            helper(node->left, ret, level + 1);
        }
        if(node->right != nullptr){
            helper(node->right, ret, level + 1);
        }
    }
};