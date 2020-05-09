#include <vector>
#include <stack>
#include <algorithm>
using std::swap;
using std::stack;
using std::vector;

/**
 * Definition for a binary tree node.
 **/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //solution 1 , leetcode official solution, some error???
    void recoverTree(TreeNode* root){
        vector<int> nums;
        inorder(root, nums);
        auto ret = findTwoSwapped(nums);
        recover(root, 2, ret[0], ret[1]);
    }
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == nullptr) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    vector<int> findTwoSwapped(vector<int> nums){
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; i++){
            //if the left child is greater parent swap
            if(nums[i + 1] < nums[i]){
                y = nums[i + 1];
                if(x == -1) {// first swap occurence
                    x = nums[i];
                }else{// second swap occurence
                    break;
                }
            }
        }
        return vector<int>{x, y};
    }
    void recover(TreeNode* root, int count, int x, int y){
        if(root != nullptr){
            if(root->val == x || root->val == y){
                root->val = root->val == x ? y : x;
                if(--count == 0) return;
            }
            recover(root->left, count, x, y);
            recover(root->right, count, x, y);
        }
    }
    

    //solution 2 in-order 
    void recoverTree(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode *x = nullptr, *y = nullptr, *prev = nullptr;

        while(!st.empty() || root != nullptr){
            while(root != nullptr){//add the left child
                st.push(root);
                root = root->left;
            }
            //get the left most chld
            root = st.top();
            st.pop();
            //if the left < parent, swap it
            if(prev != nullptr && root->val < prev->val){
                y = root;
                if(x == nullptr) x = prev;
                else break;
            }
            prev = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }

    //solution 4 morris traverse
    void recoverTree(TreeNode* root) {
        // predecessor is a Morris predecessor. 
        // In the 'loop' cases it could be equal to the node itself predecessor == root.
        // pred is a 'true' predecessor, 
        // the previous node in the inorder traversal.
        TreeNode *x = nullptr, *y = nullptr, *prev = nullptr, *predecessor = nullptr;

        while(root != nullptr){
            // If there is a left child
            // then compute the predecessor.
            // If there is no link predecessor->right = root --> set it.
            // If there is a link predecessor->right = root --> break it.
            if(root->left != nullptr){
                // Predecessor node is one step left 
                // and then right till you can.
                predecessor = root->left;
                while(predecessor->right != nullptr && predecessor->right != root){
                    predecessor = predecessor->right;
                }
                // set link predecessor.right = root
                // and go to explore left subtree
                if(predecessor->right == nullptr){
                    predecessor->right = root;
                    root = root->left;
                }else{
                    // break link predecessor->right = root
                    // link is broken : time to change subtree and go right
                    // check for the swapped nodes
                    if(prev != nullptr && root->val < prev->val){
                        y = root;
                        if(x == nullptr) {
                            x = prev;
                        }
                    }
                    prev = root;
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }else{
                //if there is no left child ,then just to right
                //check the swap nodes
                if(prev != nullptr && root->val < prev->val){
                    y = root;
                    if(x == nullptr) {
                        x = prev;
                    }
                }
                prev = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};
class Solution2 {
    //official solution 3 recurse
    TreeNode * x, *y, *prev;
    Solution2(): x(nullptr), y(nullptr), prev(nullptr) {}
    
    void recoverTree(TreeNode* root) {
        findTwoSwapped(root);
        swap(x->val, y->val);
    }
    void findTwoSwapped(TreeNode* root){
        if(root == nullptr) return;

        findTwoSwapped(root->left);
        if(prev != nullptr && root->val < prev->val){
            y = root;
            if(x == nullptr){
                x = prev;
            }else{
                return;
            }
        }
        
        prev = root;
        findTwoSwapped(root->right);
    }
};