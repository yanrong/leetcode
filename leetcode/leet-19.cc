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

        if(n < len){
            temp = node->next;
            node->next = temp->next;
            delete temp;
        }else if (len == n){
            head = node->next;
            delete node;
        }

        return head;
    }
};