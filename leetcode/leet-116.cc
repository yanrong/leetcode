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
    //original solution BFS
    Node* connect(Node* root) {
        queue<Node*> level;
        Node *tmp = nullptr;
        if(root == nullptr){
            return root;
        }
        
        level.push(root);
        while(!level.empty()){
            int size = level.size();
            tmp = level.front();
            level.pop();
            
            if(tmp->left != nullptr){
                level.push(tmp->left);
            }
            if(tmp->right != nullptr){
                level.push(tmp->right);
            }
            for(int i = 1; i < size; i++){
                tmp->next = level.front();
                tmp = tmp->next;

                if(tmp->left != nullptr){
                    level.push(tmp->left);
                }
                if(tmp->right != nullptr){
                    level.push(tmp->right);
                }
                
                level.pop();
            }
            tmp->next = nullptr;
        }

        return root;
    }
    
    //optimize the original solution
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
    //leetcode solution BFS, genius idea
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> Q;
        Q.push(root);
        Q.push(NULL);
        while(1){
            auto cur = Q.front();
            Q.pop();
            if(cur != NULL){
                cur->next = Q.front();
                if(cur->left != NULL){
                    Q.push(cur->left);
                    Q.push(cur->right);
                }
            }
            else{
                if(Q.empty()) break;
                else Q.push(NULL);
            }
            
        }
        return root;
    }
    //leetcode solution DFS
    Node* connect(Node* root) {
        if (!root) return root;
        root->next = nullptr;
        help(root);
        return root;
    }
    void help(Node* root) {
        if (root->left) {
            root->left->next = root->right;
            help(root->left);
            if (root->next) {
                root->right->next = root->next->left;
            }
            help(root->right);
        }
    }
    
    /*leetcode official solution
    * from the root to last level layer, build the connect 
    **/
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        Node *leftMost = root;
        
        while(leftMost->left != nullptr){
            //each step, take the left most child as the head to retrieve the layer node
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the 
            // corresponding links for the next level
            Node *head = leftMost;
            while(head != nullptr){
                //connect the two child, because the perfect binary tree
                head->left->next = head->right;
                //connect 2
                //if exist siblings,
                if(head->next != nullptr){
                    head->right->next = head->next->left;
                }
                // Progress along the list (nodes on the current level)
                head = head->next;
            }
             // Move onto the next level
            leftMost = leftMost->left;
        }
        return root;
    }
};