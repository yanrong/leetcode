/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *t1 = l1, *t2 = l2, *cur = head;
        int carry = 0;
        
        while(t1 != nullptr || t1 != nullptr){
            int x = (t1 != nullptr) ? t1->val : 0;
            int y = (t2 != nullptr) ? t2->val : 0;

            int sum = carry + x + y;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if(t1 != nullptr) t1 = t1->next;
            if(t2 != nullptr) t2 = t2->next;
        }

        if(carry){
            cur->next = new ListNode(carry);
        }

        return head->next;
    }
};