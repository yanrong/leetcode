#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::swap;

template<typename T>
class quickSortAlgo{
public:
    //reference [Introduction of Algorithms 3rd edition]
    int partion(vector<T>& data, int left, int right){
        //always select the right most data as key two split the origin array
        int x = data[right];
        //index i point to the brefore one data 
        int i = left - 1;
        //index j retrieve the data
        int j = left;

        for(; j < right; j++){
            if(data[j] < x){
                //after this operation, left part is less than 
                i++;
                swap(data[i], data[j]);
            }
        }

        swap(data[i + 1], data[right]);
        return i + 1;
    }

    void quickSort_1(vector<T>& data, int left, int right){
        int pivot;
        //a data is ordered, left must no equal to right
        if(left < right){
            pivot = partion(data, left, right);
            quickSort_1(data, left, pivot - 1);
            quickSort_1(data, pivot + 1, right);
        }
    }
    /*****reference DataStruct and Algorithm in C [2nd edition]****/
    int part(vector<T>& data, int left, int right){
        //take the index at left as key
        //data[left] play a temporay store data to swap
        int key = data[left];
        
        while(left < right){
            //in right part find the one data the less than key
            while(data[right] > key && left < right){
                right--;
            }
            if(left < right){//if the range is valid
                //because the data[left] has been store in the key
                //cover the data in index left, and increment it
                data[left++] = data[right];
            }
            //in left part, find one is great than key
            while(data[left] < key && left < right){
                left++;
            }
            //in the right part
            if(left < right){
                //we have been store data[right] in left part, 
                //so directly assign the data[left] to data[right] 
                data[right--] = data[left];
            }
        }
        //now index left is pivot place , assign the key
        data[left] = key;
        return left;
    }

    void quickSort_2(vector<T>& data, int low, int high){
        int pivot;
        if(low < high){
            pivot = part(data, low, high);
            quickSort_2(data, low, pivot - 1);
            quickSort_2(data, pivot + 1, high);
        }
    }
};

int main()
{
    quickSortAlgo<int> algo;
	vector<int> data{0,-5,3,60,9,88,52,61,37,44};
	algo.quickSort_2(data, 0, data.size() - 1);
	for(auto d : data){
        std::cout << d << " ";
    }
	std::cout<<std::endl;
	return 0;
}