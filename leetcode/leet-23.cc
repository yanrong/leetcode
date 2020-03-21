#include <vector>
#include <iostream>
#include <queue>
using namespace std;

/**
Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
     ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp, *head, *pre = nullptr, *tl1, *tl2;
        int pos = 0;

        if(lists.empty()) return nullptr;
        if(lists.size() == 1) return lists.at(0);

        for(; lists[pos] == nullptr && pos < lists.size() - 1; pos++);
        head = lists[pos];
        
        for(int i = pos + 1; i < lists.size(); i++){
            if(lists[i] == nullptr) continue;
            tl2 = lists[i];
            pre = tl1 = head;
            while (tl1 && tl2){
                if(tl1->val <= tl2->val){
                    pre = tl1;
                    tl1 = tl1->next;
                    continue;
                }else{
                    temp = new ListNode(tl2->val);

                    pre->next = temp;
                    temp->next = tl1;
                    pre = pre->next;

                    tl2 = tl2->next; 
                }
            }

            while(tl2){
                temp = new ListNode(tl2->val);
                pre->next = temp;
                pre = pre->next;
                tl2 = tl2->next;
            }

            tl1 = head;
        }

        return head;
    }
    
    /**solution two, because all list is sorted linked, min heap is suit one solution**/
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        //define a new compara that compare two element in list
        auto cmp = [](ListNode *l1, ListNode * l2){
            return (l1->val > l2->val);
        };
        //create priority queue to automatically sort element, store all data's pointer
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        ListNode *dummy = new ListNode(-1);
        ListNode* p = dummy;
        //first add each head node of lists
        for(auto node : lists){
            if(node != nullptr){
                pq.push(node);
            }
        }
        //priority queue sort each node
        while(!pq.empty()){
            //link the sorted top element in priority queue
            auto temp = pq.top();
            pq.pop(); // no remove it
            p->next = temp; // we point the top element
            p = p->next; // point to the next node after sorted node return from top()
            //re-add the sorted node toe
            if(p->next != nullptr) pq.push(p->next);
        }
        
        return dummy->next;
    }
    
    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        return mergeRecurse(lists, 0, (int)lists.size() - 1);
    }
    
    ListNode* mergeRecurse(vector<ListNode*> lists, int left, int right){
        if(left > right) return nullptr;
        if(left == right) return lists[left];
        
        int mid = left + (right - left) / 2;
        ListNode *l = mergeRecurse(lists, left, mid);
        ListNode *r = mergeRecurse(lists, mid + 1, right);
        
        return merger2Lists(l, r);
    } 
    
    ListNode* merger2Lists(ListNode* l, ListNode* r){
        if(l == nullptr) return r;
        if(r == nullptr) return l;
        
        if(l->val < r->val){
            l->next = merger2Lists(l->next, r);
            return l;
        }else{
            r->next = merger2Lists(l, r->next);
            return r;
        }
    }
};