#include <queue>
using std::queue;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    //origin solution , same as leetcode-116 ????
    Node* connect(Node* root) {
        queue<Node*> level;
        Node *tmp = nullptr;
        if(root == nullptr){
            return root;
        }
        
        level.push(root);
        while(!level.empty()){
            int size = level.size();

            for(int i = 0; i < size; i++){
                tmp = level.front();
                level.pop();
                if(i != size - 1){
                    tmp->next = level.front();
                }else{
                    tmp->next = nullptr;
                }

                if(tmp->left != nullptr){
                    level.push(tmp->left);
                }
                if(tmp->right != nullptr){
                    level.push(tmp->right);
                }
            }
        }

        return root;
    }
    //leetcode solution
    Node* connect(Node* root) {
        //递归处理 
        if(!root) return NULL;
        if(root->left){
            if(root->right){
                root->left->next = root->right;
            }else{
                root->left->next = findNext(root->next);
            }
        }
        if(root->right){
            root->right->next = findNext(root->next);
        }
        //再递归处理
        connect(root->right);
        connect(root->left);
        return root;
    }
    Node* findNext(Node* root){
        if(!root) return root;
        if(root->left) return root->left;
        if(root->right) return root->right;
        return findNext(root->next);
    }
};