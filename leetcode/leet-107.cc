#include <vector>
#include <queue>
#include <algorithm>
using std::queue;
using std::vector;
using std::reverse;

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
    //origin solution 1 ShuaiTi Boring
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> level;
        queue<TreeNode*> levelTreeNode;
        TreeNode *tmpNode;

        if(root == nullptr) return ret;
        levelTreeNode.push(root); //add the root first
        
        while(!levelTreeNode.empty()){
            //get the current level node number
            for(int i = levelTreeNode.size(); i > 0; i--){
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
            //ret.insert(ret.begin(),level); // Tooo slow ??
            ret.push_back(level);
            level.clear();
        }
        reverse(ret.begin(), ret.end()); // this for speed up
        return ret;
    }

    //solution 2 leetcode genius
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        helper(res,0,root);
        reverse(res.begin(),res.end());
        return res;
    }
    void helper(vector<vector<int>> &res,int level,TreeNode *node){
        if(!node) return;
        if(res.size()==level){
            res.push_back({});
        }
        res[level].push_back(node->val);
        helper(res,level+1,node->left);
        helper(res,level+1,node->right);
    }
};