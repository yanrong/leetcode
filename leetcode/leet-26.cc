#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int mark;
        if(nums.size() < 2) return nums.size();
        mark = nums[0];
        for(vector<int>::iterator i = nums.begin() + 1;  i != nums.end(); ){
            if(mark != *i){
                mark = *i;
                i++;
                continue;
            }
            nums.erase(i);
        }

        return nums.size();
    }
    //more fast better design
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) { // if no  equal
                nums[i + 1] = nums[j]; // cover origin value
                i++;
            }
        }
        nums.erase(nums.begin() + i + 1, nums.end());
        return nums.size();
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {//if no equal, as a sort array
                i++;               //skip to next adjacent place and cover value,
                nums[i] = nums[j]; //
            }
        }
        
        return i + 1;
    }
};