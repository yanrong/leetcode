/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        ListNode *phead = dummy, *cur;
        dummy->next = head;
        //phead point to the reverse list head
        for(int i = 0; i < m - 1; i++){
            phead = phead->next;
        }
        //cur point to to reverse head list next,
        //this node will be the last node after reverse
        cur = phead->next;
        
        for(int i = m; i < n; i++){
            //each step, we move the current node to place after phead
            ListNode *t = cur->next;
            //current node point to tmp next
            cur->next = t->next;
            //move the t to previous position than node cur
            t->next = phead->next;
            //head point to temporary
            phead->next = t;
        }
        
        return dummy->next;
    }
};