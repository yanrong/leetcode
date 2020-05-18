#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //original solution, not very good
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid;
        vector<int>::const_iterator i, j;
        vector<int> mergerNums;

        for(i = nums1.begin(), j = nums2.begin();i != nums1.end() && j != nums2.end();){
            if(*i < *j){
                mergerNums.push_back(*i);
                i++;
            }else{
                mergerNums.push_back(*j);
                j++;
            }
        }

        if(i != nums1.end()){
            mergerNums.insert(mergerNums.end(), i, i + (nums1.end() - i));
        }
        if(j != nums2.end()){
            mergerNums.insert(mergerNums.end(), j, j + (nums2.end() - j));
        }

        mid = mergerNums.size() / 2;

        if((mergerNums.size() % 2)){
            return mergerNums[mid];
        }else{
            return (mergerNums[mid] + mergerNums[mid - 1])/2.0 ;
        }
    }
    //official solution
    /* if we split the data with the condition len(left) = len(right) and max(left) <= min(right)
    ** then the middle is the (max(left) + min(right)) / 2
    ** there must be two condition is required 1. a[i] >= b[j - 1] and a[i - 1] <= b[j]
    ** 2. if the n and m is length of two data, and the respectively split index is i and j
    ** if cut in the middle, there have i + j = (m + n) - (i + j) or ( m - i + n - j + 1)
    ** for i in [0, m) j = (m + m + 1) / 2 - i;
    **/
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int m, n, iMin, iMax, halfLen,minRight, maxLeft, i, j;

        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        m = nums1.size();
        n = nums2.size();
        iMin = 0; iMax = m; halfLen = (m + n + 1) / 2;

        while(iMin <= iMax){
            i = (iMin + iMax) / 2;
            j = halfLen - i;
            //is to small
            if(i < iMax && nums2[j - 1] > nums1[i]){
                iMin = i + 1;
            }else if(i > iMin && nums1[i - 1] > nums2[j]){
                iMax = i - 1;//it too big
            }else{ //prefect
                maxLeft = 0;
                //i == 0 or j == 0 to judge the border
                if(i == 0){
                    maxLeft = nums2[j - 1];
                }else if(j == 0){
                    maxLeft = nums1[i - 1];
                }else{//in normal condition, select the small 
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);
                }
                //if the data length is odd, the current one is the middle data
                if(((m + n) % 2) == 1) return maxLeft;

                minRight = 0;
                if (i == m){
                    minRight = nums2[j];
                }else if(j == n){
                    minRight = nums1[i];
                }else{
                    minRight = min(nums1[i], nums2[j]);
                }
                //get the middle that the data length is even
                return (maxLeft + minRight) / 2.0;
            } 
        }
        return 0.0;
    }
};


int main(int argc, char *argv[])
{
    double result;
    Solution s;
    vector<int> a, b;
    int c[] = { 3, 7};
    int d[] = { 5};
    a.assign(c, c+2);
    b.assign(d, d +1);
    result = s.findMedianSortedArrays(a, b);
    cout<< "result = " << result << endl;
}