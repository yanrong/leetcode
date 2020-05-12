#include <vector>
using std::vector;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        // always choose left middle node as a root [solution 1] faster
        int mid = (left + right) / 2;
        // always choose right middle node as a root [ solution 2 ]
        if ((left + right) % 2 == 1) ++mid;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};