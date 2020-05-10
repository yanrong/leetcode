#include <deque>
using std::deque;

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
    //origin solution 1
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr ){
            return q == nullptr ? true : false;
        }
        if(q == nullptr){
            return p == nullptr ? true : false;
        }
        
        if(p->val == q->val){
            return isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
        }else{
            return false;
        }
    }
    //official solution 2
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        
        if(q->val != p->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    //leetcode official solution 3
    bool check(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr) return true;
        if(t1 == nullptr || t2 == nullptr) return false;
        if(t1->val != t2->val) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(check(p, q) == false) return false;
        
        deque<TreeNode*> deqP, depQ;
        deqP.push_back(p);
        depQ.push_back(q);
        while(!deqP.empty()){
            p = deqP.front();
            deqP.pop_front();
            q = depQ.front();
            depQ.pop_front();
            
            if(!check(q, p)) return false;
            if(p != nullptr){
                if(check(p->left, q->left) == false) return false;
                if(p->left != nullptr){
                    deqP.push_back(p->left);
                    depQ.push_back(q->left);
                }
                
                if(!check(p->right, q->right)) return false;
                if(p->right != nullptr){
                    deqP.push_back(p->right);
                    depQ.push_back(q->right);
                }
            }
        }
        return true;
    }
};