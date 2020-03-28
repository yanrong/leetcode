#include<iostream>
using namespace std;
/** Definition for singly-linked list. **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret, *post, *pre;
        int temp;
        if(head == nullptr || head->next == nullptr) return head;
        ret = pre = head;
        post = head->next;

        while(pre && post){
            temp = post->val;
            post->val = pre->val; 
            pre->val = temp;

            pre = post->next;
            post = ((pre == nullptr) ? nullptr: pre->next) ;
        }

        return ret;
    }
    
    /**official solution**/
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        /** recurse the whole list,and return the last one to return and backtrace
        *** after finish a times recurse, head and head->next has been in right place
        **/
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;
        //after swap, return the prev node
        return secondNode;
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        while(head && head->next){
            ListNode* first = head;
            ListNode* second = head->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
            head = first->next;
        }
        
        return dummy->next;
    }
};