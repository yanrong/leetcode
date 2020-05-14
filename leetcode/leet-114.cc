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
    //solution 1, preorder traversal, genius guy
    /*
         1
        / \
       2   5
      / \   \
     3   4   6

         1
        / \
       2   5
        \   \
         3   6
          \    
           4

       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6
    */
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        if(root->left != nullptr){
            flatten(root->left);
        }
        if(root->right != nullptr){
            flatten(root->right);
        }
        
        //record the root right tree
        TreeNode *tmp = root->right;
        //make root->right point to the root left
        root->right = root->left;
        root->left = nullptr;
        //search the real root rith
        while(root->right != nullptr){
            root = root->right;
        }
        root->right = tmp;
    }

    //solution 2
    /**
     *       1
            / \
           2   5
          / \   \
         3   4   6

           1
            \
             2
            / \
           3   4
                \
                 5
                  \
                   6

           1
            \
             2
              \
               3
                \
                 4
                  \
                   5
                    \
                     6
    **/
    void flatten(TreeNode* root) {
        TreeNode *cur = root, *tmp = nullptr;
        while(cur){
            if(cur->left != nullptr){
                //get the left tree's most right child
                tmp = cur->left;
                while(tmp->right != nullptr){
                    tmp = tmp->right;
                }
                //insert it to right child
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            //search the right tree
            cur = cur->right;
        }
    }
};