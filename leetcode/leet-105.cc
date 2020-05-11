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
    /** DFS
    * construct a tree from preoder and inorder traversal,
    * for preoder traversal, the first data must be the root of the tree or sub-tree, so we search it in
    * in order traversal,  the finding index in inorder separated the tree in two part, left part
    * is the left, and the right part is right tree,
    * we define a specified range to build the tree and sub tree, the init value is from zero to last
    * node of tree traversal [0, n], take the recursive policy to build the tree. and representative
    * given the left and right tree range in inorder and preorder
    * 
    **/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
        //if no more node to build return null pointer
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }
        /*
        * this part is crucial,found the "root" index
        */
        int i = 0;
        for(i = inStart; i <= inEnd; i++){
            if(preorder[preStart] == inorder[i]){
                break;
            }
        }
        //crate the "root" node
        TreeNode *root = new TreeNode(preorder[preStart]);
        /* 
        * the (i - inStart) indicated OFFSET of preStart, the left tree node for the 
        * preorder,[preStart + 1, preStart + 1 + OFFSET]
        * for inorder, from the beginning to OFFSET [inStart, i - 1]
        */
        root->left = helper(preorder, preStart + 1, preStart + (i - inStart), inorder, inStart, i - 1);
        /**
         * for the right node in preoder the range is [preStart + 1 + OFFSET, preEnd],
         * in inorder the range is [i + 1, inEnd]
         * the indices in inorder is i + 1 or i - 1 , where is i go ???, it has been create the "root"
        **/
        root->right = helper(preorder, preStart + (i - inStart) + 1, preEnd, inorder, i + 1, inEnd);

        return root;
    }
    
    /**
    * BFS from the leetcode genius guy
    **/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return 0;
        }
        
        stack<TreeNode*> trees;
        int pre = 0, in = 0;
        TreeNode* node = new TreeNode(preorder[pre]);
        TreeNode* root = node;
        trees.push(node);
        pre++;
        while(pre < preorder.size()){
            if(node->val == inorder[in]){
                //search to until no equal, each one is unique data
                while(!trees.empty() && trees.top()->val == inorder[in]){
                    node = trees.top();
                    trees.pop();
                    in++;
                }
                node->right = new TreeNode(preorder[pre]);
                node = node->right;
                trees.push(node);
                pre++;
            }else{
                //the root take the firs data in preorder, this very similar to the recursive policy
                //the node is not equal to inrder[in],it has been prove that the node must be left tree
                node->left = new TreeNode(preorder[pre]);
                node = node->left;
                trees.push(node);
                pre++;
            }
        }
        return root;
    }
    /*solution 3 leetcode genius 
    * 规律：对于inorder序列，最左边的一定是整个树的leftmost。
    * 这样，从左☞右遍历pre，直到pre[i] == in[0], 便找到了leftmost。同时，将A B 压入栈 。
    * 规律：对于栈中  A 一定 是 B 的父节点。即前一个一定是后一个的父节点。
    * 然后 依次 s.pop 和in[j] 对照。 如果 s.peek() != in[j]说明 pre[i] 就是s.peek的右孩子。
    */
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size(); 
        if(n == 0) return nullptr;
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(pre[0]), *cur = root;
        
        for(int i = 1, j = 0; i < n; i++){
            if(cur->val != in[j]){//找到cur的leftmost
                cur->left = new TreeNode(pre[i]);
                s.push(cur);
                cur = cur->left;
            }else{
                j++;//leftmost在in中的的下一个
                while(!s.empty() && s.top()->val == in[j]){//找到最近的有右孩子的 父节点
                    j++;
                    cur = s.top();
                    s.pop();
                }//
                cur->right = new TreeNode(pre[i]);//此时父节点的右孩子一定是 pre 中leftmost的下一个
                cur = cur->right;
            }
        }
        return root;
    }
};