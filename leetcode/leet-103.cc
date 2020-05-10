#include <vector>
#include <queue>
using std::vector;
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
    /*************************DFS(depth first search)************************/
    //solution 1 originate from leetcode official
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr){
            return ret;
        }
        dfs(root, ret, 0);
        return ret;
    }
    void dfs(TreeNode* root, vector<vector<int>>& ret, int level){
        if(ret.size() <= level){
            /*vector<int> newLevel(1, root->val);
            newLevel.push_back(root->val);*/
            ret.push_back(vector<int> (1, root->val));
        }else{
            if(level % 2 == 0){
                ret[level].push_back(root->val);
            }else{
                ret[level].insert(ret[level].begin(), root->val);
            }
        }
        
        if(root->left != nullptr){
            dfs(root->left, ret, level + 1);
        }
        if(root->right != nullptr){
            dfs(root->right, ret, level + 1);
        }
    }
    
    //solution 2 inspired by leetcode official
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr){
            return ret;
        }
        helper(root, ret, 0);
        return ret;
    }
    void helper(TreeNode* root, vector<vector<int>>& ret, int level){
        // if reach new layer, add a empty vector to record the result
        if(ret.size() <= level){
            ret.push_back({}); 
        }
        /**
        ** main idea: because the visit order is left and right, so if is odd times, 
        ** the visit order should be right and left, so we need add the right before in 
        ** left, if in prime times include zero(0), place it in order
        **/
        if(level % 2 == 0){
            ret[level].push_back(root->val);
        }else{
            ret[level].insert(ret[level].begin(), root->val);
        }
        //the visited order is left and right
        if(root->left){
            helper(root->left, ret, level + 1);
        }
        if(root->right){
            helper(root->right, ret, level + 1);
        }
    }
    /*************************BFS(broad first search)************************/
    //solution 3 from leetcode official
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr){
            return ret;
        }
        
        queue<TreeNode*> q{{root, nullptr}};
        bool isOrderLeft = true;
        vector<int> level;
        
        while(!q.empty()){
            int size = q.size();
            TreeNode* tmpNode  = q.front();
            q.pop();
            if(tmpNode != nullptr){
                //left->right order
                if(isOrderLeft){
                    level.push_back(tmpNode->val);
                }else{//right -> left order
                    level.insert(level.begin(), tmpNode->val);
                }
                //visit left and right
                if(tmpNode->left){
                    q.push(tmpNode->left);
                }
                if(tmpNode->right){
                    q.push(tmpNode->right);
                }
            }else{
                //record the result
                ret.push_back(level);
                level.clear();
                if(q.size() > 0){
                    //add null to stop
                    q.push(nullptr);
                }
                //revser flag
                isOrderLeft = !isOrderLeft;
            }
        }
        return ret;
    }
    //origin solution 4
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr){
            return ret;
        }
        
        queue<TreeNode*> q{{root}};
        bool isOrderLeft = true;
        vector<int> level;
        
        while(!q.empty()){
            int size = q.size();
            level.clear();
            for(int i = 0; i < size; i++){
                TreeNode *tmpNode = q.front();
                q.pop();
                if(isOrderLeft){
                    level.push_back(tmpNode->val);
                }else{
                    level.insert(level.begin(), tmpNode->val);
                }
                if(tmpNode->left){
                    q.push(tmpNode->left);
                }
                if(tmpNode->right){
                    q.push(tmpNode->right);
                }
            }
            isOrderLeft = !isOrderLeft;
            ret.push_back(level);
        }
        return ret;
    }
};