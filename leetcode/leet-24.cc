#include<iostream>
using namespace std;
/** Definition for singly-linked list. **/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret, *post, *pre;
        int temp;
        if(head == nullptr) return head;
        ret = pre = head;
        post = head->next;

        while(pre && post){
            temp = post->val;
            post->val = pre->val; 
            pre->val = temp;

            pre = post->next;
            post = pre == nullptr ? nullptr: pre->next ;
        }

        return ret;
    }
};