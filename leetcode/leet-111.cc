#include <algorithm>
#include <climits>
#include <utility>
#include <stack>

using std::stack;
using std::pair;
using std::min;
using std::make_pair;

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
    //solution 1 DFS
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        //why plus 1 , if root is not empty, the tree height is 1
        if(root->left == nullptr){
            //if left child is empty, calculate the right
            return 1 + minDepth(root->right);
        }else if(root->right == nullptr ){
            //if right is empty, calculate the left
            return 1 + minDepth(root->left);
        }else{
            //if the two child is not empty, calculate the depth
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
    //solution 2
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        if((root->left == nullptr) && (root->right == nullptr)){
            //both child is empty, the tree height is 1
            return 1;
        }
        
        int depth = INT_MIN;
        if(root->left != nullptr){
            //depth always is the minimun depth of right 
            depth = min(minDepth(root->right), depth);
        }
        if(root->right != nullptr){
            //get the minimun left and right
            depth = min(minDepth(root->right), depth);
        }
        //get the minimum child
        return depth;
    }
    //official solution 3,BFS
    int minDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        
        if(root == nullptr){
            return 0;
        }
        //we calculate from root to leaf
        st.push(make_pair(root, 1));
        
        int depth = 0, ret = INT_MAX;
        while(!st.empty()){
            pair<TreeNode*, int> current = st.top();
            st.pop();
            root = current.first;
            depth = current.second;
            //because from root the leaf, if there no more leafs, 
            if(root->left == nullptr && root->right == nullptr){
                //ret get the minimum between left and right 
                ret = min(ret, depth);
            }
            //get the left depth
            if(root->left != nullptr){
                st.push(make_pair(root->left, 1 + depth));
            }
            //get the right depth
            if(root->right != nullptr){
                st.push(make_pair(root->right, 1 + depth));
            }
        }
        return ret;
    }
};