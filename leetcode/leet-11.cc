#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //the total range in index 0 to last one
        vector<int>::iterator i = height.begin(), j = height.end() - 1;
        int temp, ret = 0;
        while(i != j){
            //j - i is the width, the area always depdent on small side
            temp = (j - i) * min(*i, *j);
            ret = max(temp, ret); // get the max area
            if(*i < *j) i++; // the width move to larger one
            else j--;
        } 

        return ret;
    }
    
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for(int i = 0; i < height.size(); i++){ //select the height[i] as the height
            for(int j = i + 1; j < height.size(); j++){ // search in i + 1 to last one and calculate the all area and get the largest one
                maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
            }
        }
        return maxArea;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> v1(arr, arr + sizeof(arr)/sizeof(int));
    cout << "S = " <<  s.maxArea(v1) << endl;
    return 0;
}empty