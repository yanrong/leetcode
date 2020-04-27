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
    /**
    * This is a genius idea, alloc the two node, it seems like two needle sew the List as request
    * and do not destroy the original data sequence 
    **/
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftDummy = new ListNode(-1);
        ListNode *rightDummy = new ListNode(-1);
        ListNode *left = leftDummy, *right = rightDummy;
        
        while(head != nullptr){
            //two needles point to each part with specific condition
            if(head->val < x){
                left->next = head;
                left = left->next;
            }else{
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        //right part pointer to null
        right->next = nullptr;
        //joint the two part, left is less or equal the right part
        left->next = rightDummy->next;
        //return the head node
        return leftDummy->next;
    }
};