#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator i = height.begin(), j = height.end() - 1;
        int temp, ret = 0;
        while(i != j){
            temp = (j - i) * min(*i, *j);
            ret = max(temp, ret);
            if(*i < *j) i++;
            else j--;
        } 

        return ret;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> v1(arr, arr + sizeof(arr)/sizeof(int));
    cout << "S = " <<  s.maxArea(v1) << endl;
    return 0;
}