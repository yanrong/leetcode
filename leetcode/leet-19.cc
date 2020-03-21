#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp, *node;
        int len = 0;
        if(head == nullptr) return nullptr;
        if(n <= 0) return head;

        temp = head; node = head;
        for( ; temp; temp = temp->next, len++){
            if(len > n) node = node->next;    
        }

        if(n < len){//in middle link list
            temp = node->next;
            node->next = temp->next;
            delete temp;
        }else if (len == n){
            head = node->next;
            delete node;
        }

        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = head;
        ListNode *second = dummy;
        // Advances first pointer so that the gap between first and second is n nodes apart
        for(int i = 0 ; i <= n; i++){
            first = first->next;
        }
        
        //move first to the end, maintaining the gap;
        while(first != nullptr){
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};