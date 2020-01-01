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
        ListNode *temp, *head, *post = nullptr, *tl1, *tl2;
        if(lists.empty()) return nullptr;
        if(lists.size() == 1) return lists.at(0);

        tl1 = head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            tl2 = lists[i];
            while (tl1 && tl2){
                while(tl1->val <= tl2->val){
                    post = tl1->next != nullptr ? tl1->next->next : nullptr;
                    tl1 = tl1->next;
                }

                temp = new ListNode(tl2->val);
                tl2 = tl2->next; 
                tl1->next = temp;
                temp->next = post;

                tl1 = tl1->next != nullptr ? tl1->next->next : nullptr;
                post = tl1->next != nullptr ? tl1->next->next : nullptr;
            }

            tl1 = head;
        }

        return head;
    }
};