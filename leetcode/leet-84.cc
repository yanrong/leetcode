#include <vector>
#include <stack>
using std::stack;
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    //emulate all possible by violence [Over time limit]
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int minHeight = heights[i];
            for(int j = i; j < heights.size(); j++){
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight *(j - i + 1));
            }
        }
        return maxArea;
    }
    //solution 2
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, minHeight, tmp;
        for(int i = 0; i < heights.size(); i++){
            //each time get a peak in a ascenging range
            while((i + 1) < heights.size() && heights[i] <= heights[i + 1]){
                i++;
            }
            minHeight = heights[i];
            //the smallest height determine the Area
            for(int j = i; j >= 0; j--){
                //get smallest height
                minHeight = min(minHeight, heights[j]);
                //calaulate the max area
                maxArea = max(maxArea, minHeight * (i - j + 1));
            }
        }
        return maxArea;
    }

    // use the stack to emulate the solution 2
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        heights.push_back(0); // to stop at last one
        for(int i = 0; i < heights.size(); i++){
            //get an ascening range
            if(st.empty() || heights[st.top()] < heights[i]){
                st.push(i);
            }else{
                //if the top is greater the heights[i], calculate the all maxArea
                int top = st.top();
                st.pop();
                //the finally postion is i - 1, each step we have been pop a element,
                //the stack hold the index, so i - 1 - st.top is right distance
                //if we pop to stack empty, that like i - 0
                maxArea = max(maxArea, heights[top] *(st.empty() ? i : (i - 1 - st.top())));
                // why i-- for i is suspending at heights[st.top()] <= heights[i],
                // the loop will increment 1 in i in each step
                i--; 
            }
        }
        return maxArea;
    }

    //update version for leetcode
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        heights.push_back(0); // to stop at last one
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int top = st.top();
                st.pop();
                maxArea = max(maxArea, heights[top] *(st.empty() ? i : (i - 1 -st.top())));
            }
            st.push(i);
        }
        return maxArea;
    }

    //official solution
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        st.push(-1);

        for(int i = 0; i < heights.size(); i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                int topHeight = st.top();
                st.pop();
                maxArea = max(maxArea, heights[topHeight] * (i - st.top() + 1));
            }
            st.push(i);
        }
        while(st.top() != -1){
            int topHeight = st.top();
            st.pop();
            maxArea = max(maxArea, heights[topHeight] * ((int)heights.size() - st.top() - 1));
        }
        return maxArea;
    }
};


// leetcode recommand
// Largest Rectangle in Histogram
// Stack solution, O(NlogN) solution
class SegTreeNode {
public:
    int start;
    int end;
    int min;
    SegTreeNode *left;
    SegTreeNode *right;
    SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        left = right = NULL;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        // first build a segment tree
        SegTreeNode *root = buildSegmentTree(heights, 0, heights.size() - 1);
        // next calculate the maximum area recursively
        return calculateMax(heights, root, 0, heights.size() - 1);
    }
    
    int calculateMax(vector<int>& heights, SegTreeNode* root, int start, int end) {
        if (start > end) {
            return -1;
        }
        if (start == end) {
            return heights[start];
        }
        int minIndex = query(root, heights, start, end);
        int leftMax = calculateMax(heights, root, start, minIndex - 1);
        int rightMax = calculateMax(heights, root, minIndex + 1, end);
        int minMax = heights[minIndex] * (end - start + 1);
        return max( max(leftMax, rightMax), minMax );
    }
    
    SegTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
        if (start > end) return NULL;
        SegTreeNode *root = new SegTreeNode(start, end);
        if (start == end) {
            root->min = start;
            return root;
        } else {
            int middle = (start + end) / 2;
            root->left = buildSegmentTree(heights, start, middle);
            root->right = buildSegmentTree(heights, middle + 1, end);
            root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
            return root;
        }
    }
    
    int query(SegTreeNode *root, vector<int>& heights, int start, int end) {
        if (root == NULL || end < root->start || start > root->end) return -1;
        if (start <= root->start && end >= root->end) {
            return root->min;
        }
        int leftMin = query(root->left, heights, start, end);
        int rightMin = query(root->right, heights, start, end);
        if (leftMin == -1) return rightMin;
        if (rightMin == -1) return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    }
};