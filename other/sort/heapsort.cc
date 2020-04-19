#include <vector>
#include <iostream>
using std::vector;
using std::swap;

class Solution {
public:
    /*****heap sort  from DataStruct and [Algorithm in C 2nd edition]****/
    inline int leftChld(int i){
		//left child
        return 2 * i + 1;
    }
    void precDown(vector<int> &nums, int i, int n){
        int child, tmp;
        
        //tmp is the parent node, if the left child is not out bound
        for(tmp = nums[i]; leftChld(i) < n; i = child){
            child = leftChld(i); // get the left child
			//if the left child is not the last data in array, 
			//judge the left and right node, get the larger one
            if((child != n - 1) && (nums[child + 1] > nums[child])){
                child++;
            }
			// get the large one in parent node and it's sibling 
            if(tmp < nums[child]){
                nums[i] = nums[child];
            }else{
                //if the parent is greater than it's sibling, break
                break; 
            }
        }
        //the loop sort the parent and it' sibling, if a child is disorder comparing to parent,
        // continue to sort the child's child, finally, the nums[i] is right place to tmp 
        nums[i] = tmp;
    }
    
    void heapSort(vector<int> &nums){
        int n = nums.size();
        if(n < 1) return;
        for(int i = n / 2; i >= 0; i --){
            precDown(nums, i, n);
        }
        for(int i = n - 1; i > 0; i--){
            
            swap(nums[0], nums[i]);
            precDown(nums, 0, i);
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums{ 23, 45, 12, 90, 18, 675, 64, 543, 89, 94};
    Solution s;
    s.heapSort(nums);
    for(auto i : nums){
        std::cout << " " << i;
    }
    std::cout<< std::endl;
    return 0;
}

