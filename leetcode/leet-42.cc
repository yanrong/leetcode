#include <vector>
#include <stack>
using std::stack;
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    //calculate each column trap capacity O(n * n)
    //OVER LIMITED TIME
    int trap(vector<int>& height) {
        int ret = 0;
        int size = height.size();

        for(int i = 1; i < size - 1; i++){
            int maxLeft = 0, maxRight = 0;

            for(int j = i; j >= 0; j--){ //Search the left part for max bar size
                maxLeft = max(maxLeft, height[j]);
            }
            for(int j = i; j < size; j++){//Search the right part for max bar size
                maxRight = max(maxRight, height[j]);
            }
            //how many trap is depend the small sides,and add them all
            //small one puls the current height is the real trap capacity
            ret += min(maxLeft, maxRight) - height[i];
        }
        return ret;
    }
    
    //do enhance in algorithms, just do a times and record the max 
    int trap(vector<int>& height) {
        int ret = 0, size = height.size();
        if(height.size() == 0) return 0;
        
        vector<int> leftMax(size), rightMax(size);
        //from left to right, and assign the first as assume maximun in left side
        leftMax[0] = height[0];
        for(int i = 1; i < size; i++){//compare to next and get the larger one
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        //from right to left, assign the last one as assume maximun in right side
        rightMax[size - 1] = height[size - 1];
        for( int i = size - 2; i >= 0; i--){//get the larger one between previous one and the current one
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        
        for(int i = 1; i < size -1; i++){ //small one puls the current height is the real trap capacity
            ret += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ret;
    }
    /*
    * stack algorithms:
    * if the current element in array height is smaller than the element in top of stack, push it
    * otherwise, that means the value and the value in stack is  a value of trap water
    * so pop the top one, and get calculate the trap capacity
    */
    int trap(vector<int>& height) {
        int ret = 0, current = 0; //indext to search whole height[i]
        stack<int> st;
        while(current < height.size()){
            //if the stack has element and current one is greater
            while(!st.empty() && height[current] > height[st.top()]){
                int top = st.top(); // get and pop the top
                st.pop();
                if(st.empty()) break; // if there have a element, skip it
                int distance = current - st.top() - 1; // how many distance between to distance
                int bounded_height = min(height[current], height[st.top()]) - height[top]; // the lower side decided the trap capacity
                ret += distance * bounded_height; //get the trap capacity
            }
            
            st.push(current++);//stack element is the index of array height
        }
        return ret;
    }
};