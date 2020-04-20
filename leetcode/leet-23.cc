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
    //origin solution, Over time limit
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
    
    /**solution 2, because all list is sorted linked, min heap is suit one solution**/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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

    /************* soluiton 3 *************/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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

    /********** soluiton 4 simple merger 2 list************/
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int n = lists.size();
        while(n > 1){
            int k = (n + 1) / 2;
            for(int i = 0; i < n/2; i++){
                lists[i] = merge2lists(lists[i], lists[i + k]);
            }
            n = k;
        }
        
        return lists[0];
    }
    
    ListNode* merge2lists(ListNode* list1, ListNode* list2){
        ListNode* node = new ListNode(-1), *cur = node;

        while(list1 && list2){
            if(list1->val > list2->val){
                cur->next = list2;
                list2 = list2->next;
            }else{
                cur->next = list1;
                list1 = list1->next;
            }

            cur = cur->next;
        }

        if(list1) cur->next = list1;
        if(list2) cur->next = list2;

        return node->next;
    }
};