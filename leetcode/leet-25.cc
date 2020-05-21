/** Definition for singly-linked list. **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    //original solution 1 ??? very odds idea
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *post, *pre, *ret;
        int i = 1, temp;
        
        ret = post = pre = head;
        if(head == nullptr || k < 1) return nullptr;

        while(pre && i < k ){
            pre = pre->next;
            i++;
        }

        while(pre){
            i = 0;
            subReverse(post, pre->next, k);
            
            post = pre->next;
            while(pre && i < k){
                pre = pre->next;
                i++;
            };
        }

        return ret;
    }
    void subReverse(ListNode* left, ListNode *right, int k){
        ListNode *lmark,*rmark, *spre, *spost;
        int i = 1, temp;
        spost = spre = left;
        lmark = spre->next;

        if(k < 2) return;
        while(i < k){
            if(i == k - 2) rmark = spre;
            spre = spre->next;
            i++;
        }

        temp = spre->val;
        spre->val = spost->val;
        spost->val = temp;

        subReverse(lmark, rmark, k - 2);
    }
    
    /**solution 2**/
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head != nullptr && k == 1) return head;
        
        ListNode* dummy = new ListNode(-1);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        
        for(int i = 1; cur != nullptr; i++){
            if(i % k == 0){//at each reverse node, crate a function return reverse node
                pre = reverse1Group(pre, cur->next);
                cur = pre->next;//after finished a reverse, skip to next one group
            }else{//if it is not reverse node, move to next
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
    
    ListNode* reverse1Group(ListNode* head, ListNode* last){
        ListNode* prev = head->next; 
        ListNode* cur = prev->next; 
        /**insert each one before last node with range from cur to a node before next **/
        while(cur != last){
            //exchange the prev and cur node place
            prev->next = cur->next;
            cur->next = head->next;
            //head is static, head next point to cur
            head->next = cur;
            //cur point the prev next
            cur = prev->next;
        }
        //after the reverse, last one is head
        return prev;
    }
    
    /***solution 3***/
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* phead = dummy, *first = phead;
        int num = 0;
        dummy->next = head;
        //count the length
        while(first = first->next) num++;
        
        while(num >= k){
            first = phead->next;//first node
            //insert the data before cur
            for(int i = 1; i < k; i++){
                ListNode* second = first->next; //second node
                first->next = second->next; 
                second->next = phead->next; //exchange second and first node
                phead->next = second; //after swap head point to second node
            }
            phead = first;//after all reverse, first is the last one,
            num -= k; // reduce the counter
        }
        return dummy->next;
    }
};