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
    //DFS, original solution
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0 , inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int poLeft, int poRight){
        if(inLeft > inRight || poLeft > poRight){
            return nullptr;
        }

        int i;
        //find the index to split the right and left tree
        for(i = inLeft; i <= inRight; i++){
            if(inorder[i] == postorder[poRight]){
                break;
            }
        }
        TreeNode* root = new TreeNode(postorder[poRight]);
        //left tree in [poLeft, poLeft + (i - inLeft)]  poLeft + (i - inLeft) - 1 is array index
        root->left = helper(inorder, inLeft, i - 1, postorder, poLeft, poLeft + (i - inLeft) - 1);
        //right tree in range [poLeft + (i - inLeft), poRight -1]
        root->right = helper(inorder, i + 1 ,inRight, postorder, poLeft + (i - inLeft), poRight - 1);
        return root;
    }

    //BFS original solution
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0){
            return nullptr;
        }
        int in = inorder.size() - 1, post = postorder.size() - 1; 
        //for the postorder traversal, the last one data must be the root of the tree
        TreeNode *node = new TreeNode(postorder[post--]);
        TreeNode *root = node;

        stack<TreeNode*> st;
        st.push(node);

        while(post >= 0){
            //inorder last one indicate the right trees last node
            if(inorder[in] != node->val){
                //1.the postorder traversal tree order left->right->root
                //2. so the inorder last one data is the most right node of tree
                //according to above items, we create the the right tree first
                node->right = new TreeNode(postorder[post--]);
                node = node->right;
                st.push(node);
            }else{
                //back trace to the parent node
                while(!st.empty() && st.top()->val == inorder[in]){
                    node = st.top();
                    st.pop();
                    in--;//update the right most node
                }
                //create the left node
                node->left = new TreeNode(postorder[post--]);
                node = node->left;
                st.push(node);
            }
        }

        return root;
    }

    //unknow genius solution 3
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0) return nullptr;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;
        
        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 
        
        while(true){
            if(inorder.back() == stn.top()->val) {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            } else {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};