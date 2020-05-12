#include <vector>
using std::vector;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
    //solution 1, simple idea to store the list to a array O(n) in space too slow
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *phead = head;
        vector<int> data;
        while(phead != nullptr){
            data.push_back(phead->val);
            phead = phead->next;
        }
        return helper(data, 0, data.size() - 1);
    }
    TreeNode* helper(vector<int>& data, int left, int right){
        if(left > right){
            return nullptr;
        }
        int mid = (left + right) / 2;
        
        TreeNode *root = new TreeNode(data[mid]);
        root->left = helper(data, left, mid - 1);
        root->right = helper(data, mid + 1, right);
        
        return root;
    }
    
    //inspired official solution 
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, nullptr);
    }
    TreeNode* dfs(ListNode* head, ListNode* end){
        if(head == end){//there is no more data, return null
            return nullptr;
        }
        ListNode *fastPtr = head, *slowPtr = head;
        /** get the middle node
        ** in the same iterate times, slowptr step is half of the fastptr
        ** so if the fast reach the last one, slow is mid +/- 1, it doesn.t matter
        **/
        while (fastPtr != end && fastPtr->next != end){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        //slow is middle node
        TreeNode *root = new TreeNode(slowPtr->val);
        root->left = dfs(head, slowPtr);
        root->right = dfs(slowPtr->next, end);
        return root;
    }
    
    //leetcode official solution 3
    TreeNode* sortedListToBST(ListNode* head) {
        // If the head doesn't exist, then the linked list is empty
        if(head == nullptr){
            return nullptr;
        }
        // Find the middle element for the list.
        ListNode *mid = findMiddleElement(head);
        //The mid becomes the root ot BST
        TreeNode *node = new TreeNode(mid->val);
        
        //Bast case when there is just one element in the linked list
        if(head == mid){
            return node;
        }
        
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);
        
        return node;
    }
    
    ListNode* findMiddleElement(ListNode* head){
        // The pointer used to disconnect the left half from the mid node.
        ListNode *prevPtr = nullptr, *slowPtr = head, *fastPtr = head;
        // Iterate until fastPr doesn't reach the end of the linked list.
        while(fastPtr != nullptr && fastPtr->next != nullptr){
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        // Handling the case when slowPtr was equal to head.
        //cut the linked list into two part at mid point node
        if(prevPtr != nullptr){
            prevPtr->next = nullptr;
        }
        return slowPtr;
    }
};