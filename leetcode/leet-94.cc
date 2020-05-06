#include <vector>
#include <stack>
using std::stack;
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
    //solution 1 recurse origin solution
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr) return ret;
        inorderTrace(ret, root);
    }
    void inorderTrace(vector<int>& ret, TreeNode* parent){
        //this node is not empty
        if(parent){
            //try to visit left child
            inorderTrace(ret, parent->left);
            ret.push_back(parent->val); //get the root data
            inorderTrace(ret, parent->right);// visit right child
        }
    }
    //solution stack 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode *ptree = root;
        //ptree is not null add to stack, or
        while(ptree != nullptr || !st.empty()){
            while(ptree){//add the whole left child
                st.push(ptree);
                ptree = ptree->left;
            }
            //in order visit, left--parent--right
            if(!st.empty()){
                //get the left child
                ptree = st.top();
                ///visit the parent node
                ret.push_back(ptree->val);
                //discard the left
                st.pop();
                //get the right node
                ptree = ptree->right;
            }
        }
        return ret;
    }
};