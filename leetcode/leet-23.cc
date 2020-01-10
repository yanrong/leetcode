#include <vector>
#include <iostream>
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
};