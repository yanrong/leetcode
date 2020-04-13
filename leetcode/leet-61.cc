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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *phead, *cur, *prev;
        int length = 0, m;
        phead = cur = head;
        //get total length
        while(cur){
            cur = cur->next;
            length++;
        }
        //if length is 1 or zero, need do nothing
        if(length <= 1) return head;
        if(2 * length <= k){
            //double rotate is restort to original sequence, just counter how many should to rotata
            m = k % length;
        }else{
            m = k;
        }
        
        
        while(m > 0){
            phead = prev = head; cur = head->next;
            while(cur->next != nullptr){
                cur = cur->next;
                prev = prev->next;
            }
            //this is a loop list
            cur->next = head;
            //broke it
            prev->next = nullptr;
            //update the head
            head = cur;
            m--;
        }
        return head;
    }
    
    //overtime
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> loop;
        ListNode *t = head;
        int nums = k, tmp, length, m;
        while(t != nullptr){
            loop.push_back(t->val);
            t = t->next;
        }
        
        length = loop.size();
        if(length <= 1) return head;
        if(2 * length <= k){
            //double rotate is restort to original sequence, just counter how many should to rotata
            m = k % length;
        }else{
            m = k;
        }
        
        while(m > 0){
            tmp = loop.back();
            loop.pop_back();
            loop.insert(loop.begin(), tmp);
            m--;
        }
        
        t = head;
        for(int i = 0; i < loop.size() && t!= nullptr; i++){
            t->val = loop[i];
            t = t->next;
        }
        return head;
    }
};