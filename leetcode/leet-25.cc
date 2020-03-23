/** Definition for singly-linked list. **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
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
    
    /**other solution**/
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head != nullptr && k == 1) return head;
        
        ListNode* dummy = new ListNode(-1);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        
        for(int i = 1; cur; i++){
            if(i % k == 0){//at each reverse node, crate a function return reverse node
                pre = reverse1Group(pre, cur->next);
                cur = pre->next;//after finished a reverse, skip to next one group
            }else{//if it is not reverse node, skip to next
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
    
    ListNode* reverse1Group(ListNode* pre, ListNode* next){
        ListNode* last = pre->next; 
        ListNode* cur = last->next; 
        /**insert each one before last node with range from cur to a node before next **/
        while(cur != next){
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        
        return last;
    }
    
    /***solution 3***/
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy, *cur = pre;
        int num = 0;
        dummy->next = head;
        //count the length
        while(cur = cur->next) num++;
        
        while(num >= k){
            cur = pre->next;//move the cur to next group initial node
            for(int i = 1; i < k; i++){
                ListNode* t = cur->next; //mark the temp node that be insert into afpter pred
                cur->next = t->next; //
                t->next = pre->next; //skip cur node and t node order
                pre->next = t; // link it
            }
            pre = cur;//after all reverse, cur is the last one, so pre point to it.
            num -= k; // reduce the counter
        }
        return dummy->next;
    }
};