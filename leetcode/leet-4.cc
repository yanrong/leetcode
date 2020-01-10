#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid;
        vector<int>::const_iterator i, j;
        vector<int> mergerNums;

        for(i = nums1.begin(), j = nums2.begin();i != nums1.end() && j != nums2.end();){
            if(*i < *j){
                mergerNums.push_back(*i);
                cout << "i = " << *i <<endl;
                i++;
            }else{
                mergerNums.push_back(*j);
                cout << "j = " << *j <<endl;
                j++;
            }
        }

        if(i != nums1.end()){
            mergerNums.insert(mergerNums.end(), i, i + (nums1.end() - i));
        }

        if(j != nums2.end()){
            mergerNums.insert(mergerNums.end(), j, j + (nums2.end() - j));
        }
        /*
        cout << "mergerNums size "<< mergerNums.size()<< endl;
        for(vector<int>::const_iterator mi = mergerNums.begin(); mi != mergerNums.end(); mi++ )
        {
            cout<<" " << *mi;
        }
        cout << endl;*/
        mid = mergerNums.size() / 2;
        if((mergerNums.size() % 2)){
            //cout << "result 1" << mergerNums[mid] <<endl;
            return mergerNums[mid];
        }else{
            //cout<<"result 2  " << (mergerNums[mid] + mergerNums[mid - 1])/2.0 <<endl;
            return (mergerNums[mid] + mergerNums[mid - 1])/2.0 ;
        }
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