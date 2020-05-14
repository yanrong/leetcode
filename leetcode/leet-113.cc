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
    //original solution 1 DFS ShuaiTi XXXXXXXXXXXX
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if(root == nullptr){
            return ret;
        }
        vector<int> tmp;
        dfs(root, ret, tmp, sum);
        return ret;
    }

    void dfs(TreeNode* node, vector<vector<int>>& ret, vector<int> tmp, int sum){
        int subSum = 0;
        tmp.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            for(auto i : tmp){
                subSum += i;
            }
            if(sum == subSum){
                ret.push_back(tmp);
            }
            return;
        }

        if(node->left != nullptr){
            dfs(node->left, ret, tmp, sum);
        }
        if(node->right != nullptr){
            dfs(node->right, ret, tmp, sum);
        }
    }
};