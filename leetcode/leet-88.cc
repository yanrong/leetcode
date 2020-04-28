#include <vector>
#include <algorithm>
using std::vector;
using std::copy;

class Solution {
public:
    //very very simply
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> array;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] >= nums2[j]){
                array.push_back(nums2[j++]);
            }else {
                array.push_back(nums1[i++]);
            }
        }
        
        while(i < m) {
            array.push_back(nums1[i++]);
        }
        while(j < n) {
            array.push_back(nums2[j++]);
        }
        copy(array.begin(), array.end(), nums1.begin());
    }
    
    //other genius solution
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n;
        while(m > 0 && n > 0){
            if(nums1[m - 1] >= nums2[n - 1]){
                nums1[k - 1] = nums1[m - 1];
                k--; m--;
            }else{
                nums1[k - 1] = nums2[n - 1];
                k--; n--;
            }
        }
        while(n > 0){
            nums1[k - 1] = nums2[n -1];
            k--; n--;
        }
    }
};