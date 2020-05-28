/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //this is a genius design, alloc a guard pointer
        ListNode *node = new ListNode(-1);
        ListNode *phead, *cur, *tmp;
        phead = node; //point th the dummy node
        node->next = head; // guard pointer point to the list head
        
        while(phead->next){// if the list is not empty
            cur = phead->next; // get the first one node
            //search the node with same val
            while(cur->next && cur->val == cur->next->val){
                tmp = cur; // temporary store it
                cur = cur->next; // move to next
                delete tmp; //delete it
            }
            if(cur != phead->next){ // if there have same value node
                //if there has more than two data with same value, 
                //the last cur point to the last same value node
                phead->next = cur->next; // skip to cur->next
                delete cur; //delete the cur
            }else{
                phead = phead->next;//if no same value data, phead skip to next
            }
        }
        head = node->next;
        delete node;//avoiding return the local variable which allocated by dynamic
        return head;
    }
};