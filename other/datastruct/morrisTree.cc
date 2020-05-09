#include <iostream>
using std::cout;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
**当前节点用cur表示
** 1）如果cur无左孩子，cur向右移动cur=cur->right
** 2）如果cur有左孩子，找到cur左子树的最右节点，记为mostright：
**     如果mostright的右指针为空 让其指向cur,mostright->right=cur，cur向左移动，cur=cur->left;
**     如果mostright的右指针指向cur 让其指向空 mostright->right=null cur向右移动，cur=cur->right;
**/
class morrisTree{
public:
    void morrisPreorder(TreeNode* root){
        if(root == nullptr){
            return ;
        }
        TreeNode *cur = root;
        TreeNode *mostRight = nullptr;
        while (cur != nullptr)
        {
            mostRight = cur->left;
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur; // right point to parent
                    //get the value, next step will visit right child
                    cout<< cur->val<< " ";
                    cur = cur->left;
                    //why continue, we have been reach the left-right most, 
                    //next step visit left child
                    continue;
                }else{
                    mostRight->right = nullptr;
                }
            }else{//if the left child is empty, visit parent node
                cout<<cur->val<<" ";
            }
            cur = cur->right;
        }
    }

    void morrisInorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        TreeNode *cur = root, *mostRight = nullptr;
        while(cur != nullptr){
            mostRight = cur->left; //visit the left tree
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                }
            }
            cout<<cur->val<<" ";
            cur = cur->right;
        }
    }

    void morrisPostorder(TreeNode* root){
        if(root != nullptr){
            return;
        }
        TreeNode *cur = root, *mostRight = nullptr;
        while(cur != nullptr){
            mostRight = cur->left;
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                    printEdge(cur->left);
                }
            }
            cur = cur->right;
        }
        printEdge(root);
    }

    void printEdge(TreeNode *root){
        root = rightReverse(root);
        TreeNode *cur = root;
        while(cur != nullptr){
            cout<<cur->val<< " ";
            cur = cur->right;
        }
        rightReverse(root);
    }

    TreeNode* rightReverse(TreeNode *root){
        TreeNode *cur = root->right, *prev = root;
        prev->right = nullptr;
        while(cur != nullptr){
            TreeNode *tmp = cur;
            cur = cur->right;
            tmp->right = prev;
            prev = tmp;
        }
        return prev;
    }
};