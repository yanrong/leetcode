
/** Definition for singly-linked list. **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**this is an resolution of question, reverse  k node from head node **/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ret, *temp, *thead;
        int i = 0;

        if(head == nullptr) return nullptr;
        if(k < 2) return head;

        ret = new ListNode(-1);
        thead = head;
        while(thead && i < k){
            temp = thead;
            thead = thead->next;
            temp->next = ret->next;
            ret->next = temp;
            i++; 
        }
        
        if(thead != nullptr){
            temp = ret->next;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = thead;
        }

        return ret->next;
    }
};