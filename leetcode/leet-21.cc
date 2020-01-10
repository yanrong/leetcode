#include<iostream>

/*Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *retNode, *trace, *temp;

        if(l1 == nullptr && l2 == nullptr) return nullptr;
        if(l1 == nullptr && l2 != nullptr) return l2;
        if(l2 == nullptr && l1 != nullptr) return l1;
        
        if(l1->val <= l2->val){
            retNode = new ListNode(l1->val);
            l1 = l1->next;
        }else{
            retNode = new ListNode(l2->val);
            l2 = l2->next;
        }
        trace = retNode;

        while (l1 && l2)
        {
            if(l1->val >= l2->val){
                temp = new ListNode(l2->val);
                l2 = l2->next;
            }else{
                temp = new ListNode(l1->val);
                l1 = l1->next;
            }

            trace->next = temp;
            trace = trace->next;
        }
        
        while(l1){
            temp = new ListNode(l1->val);
            trace->next = temp;
            trace = trace->next;
            l1 = l1->next;
        }

        while(l2){
            temp = new ListNode(l2->val);
            trace->next = temp;
            trace = trace->next;
            l2 = l2->next;
        }

        return retNode;
    }
};