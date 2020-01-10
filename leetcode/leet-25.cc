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
};