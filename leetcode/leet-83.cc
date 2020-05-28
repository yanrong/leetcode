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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev, *cur, *tmp;
        if(head == nullptr || head->next == nullptr) return head;
        prev = head;
        //like delete the same value in array
        while(prev->next){
            cur = prev->next;//get then guard prev next value
            if(cur->val == prev->val){
                //delete the same value
                while(cur && cur->val == prev->val){
                    tmp = cur;
                    prev->next = cur->next; // delete the cur, prev next skip it
                    //cur = prev->next; //this is more resonable
                    cur = prev->next;//cur move to next
                    delete tmp;
                }
            }else{
                prev = prev->next;
            }
        }
        return head;
    }

    //derive from leetcode
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *p = head, *q = head->next;
        while(q){
            if(p->val == q->val){
                p->next = q->next;
                q = p->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};