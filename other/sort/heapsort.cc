#include <vector>
#include <iostream>
using std::vector;
using std::swap;

class Solution {
public:
    /*****heap sort from DataStruct and Algorithm in C [2nd edition]****/
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

    //heapSort from [Introduction of Algorithms 3rd edition]
    inline int left(int i){
        return 2 * i;
    }
    inline int right(int i){
        return 2 * i + 1;
    } 

    void maxHeapify(vector<int>& array, int i, int size){
        int l = left(i);
        int r = right(i);
        int largest;

        if(l <= size and array[l] > array[i]){
            largest = l;
        }else{
            largest = i;
        }
        if(r <= size and array[r] > array[largest]){
            largest = r;
        }
        
        if(largest != i){
            swap(array[i], array[largest]);
            maxHeapify(array, largest, size);
        }
    }

    void buildMaxHeap(vector<int>& arrray){
        int size = arrray.size() - 1;
        for(int i = size / 2; i >= 1; i--){
            maxHeapify(arrray, i, size);
        }
    }

    void heapSort2(vector<int>& array){
        buildMaxHeap(array);
        for(int i = array.size() - 1; i >= 2; i--){
            swap(array[1], array[i]);
            maxHeapify(array, 1, i - 1);
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    const int INFINIT = -10000;
    vector<int> nums{ 23, 45, 12, 90, 18, 675, 64, 543, 89, 94};
    vector<int> nums2{INFINIT ,23, 45, 12, 90, 18, 675, 64, 543, 89, 94};
    Solution s;
    //s.heapSort(nums);
    s.heapSort2(nums2);
    for(auto i : nums2){
        std::cout << " " << i;
    }
    std::cout<< std::endl;
    return 0;
}

