#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
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