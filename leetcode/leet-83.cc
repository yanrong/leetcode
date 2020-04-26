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
        
        while(prev->next){
            cur = prev->next;
            if(cur->val == prev->val){
                while(cur && cur->val == prev->val){
                    tmp = cur;
                    prev->next = cur->next;
                    cur = prev->next;
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
        ListNode *p=head, *q=head->next;
        while(q){
            if(p->val==q->val){
                p->next=q->next;
                q=p->next;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};