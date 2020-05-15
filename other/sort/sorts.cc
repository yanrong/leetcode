#include <vector>
#include <iostream>
#include <algorithm>
using std::swap;
using std::vector;

template<typename T>
class sortsAlgo{
public:
    /**
     * Bubble Sort, 
     * the data length is N, for bubble sort we need N - 1 times to finished the sort,
     *  every times, we swap the adjacent data as we define order, in each step, the 
     * finally result is biggest or smallest is swap to to "end of data"
     * **/
    void bubbleSort(vector<T>& data){
        int n = data.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(data[j + 1] < data[j]){
                    swap(data[j + 1], data[j]);
                }
            }
        }
    }
    /**
     * insert sort like play poker, if only have a data, it is ordered
     * the index start at 1 to last one, find the right place to insert 
     * the key, 
     **/
    void insertSort_1(vector<T>& data){
        for(int i = 1; i < data.size(); i++){
            //if need exchange, swap the data until in right place with specific condition
            for(int j = i; j > 0 && (data[j - 1] > data[i]); j--, i--){
                swap(data[i], data[j - 1]);
            }
        }
    }
    void insertSort_2(vector<T>& data){
        int tmp, j;
        for(int i = 1; i < data.size(); i++){
            tmp = data[i];
            for(j = i; j > 0 && (data[j - 1] > tmp); j--){
                data[j] = data[j - 1];
            }
            data[j] = tmp;
        }
    }
    /**
     * select sort
     * at beginning, select a index to represent the smallest or largest data index,
     * seach in rest of data and find one which is big or small than index, if necessary
     * swap the data
     * */
    void selectSort(vector<T>& data){
        int n = data.size(), index;
        //select data select index is from 0 to n - 1
        for(int i = 0; i < n - 1 ; i++){
            index = i;
            for(int j = i + 1; j < n; j++){
                if(data[j] < data[index]){
                    index = j;
                }
            }
            //if need to exchange
            if(index != i){
                swap(data[index], data[i]);
            }
        }
    }
    //shell sort
    void shellSort(vector<T>& data){
        int tmp, j;
        int n = data.size();
        //each time take the half length as the gap to exchange the data
        for(int increment = n / 2; increment > 0; increment /= 2){
            //from the increment to data length
            for(int i = increment; i < n; i++){
                tmp = data[i]; //store the data[i]
                for(j = i; j >= increment; j -= increment){
                    //exchange the data with gap increment
                    if(tmp < data[j - increment]){
                        data[j] = data[j - increment];
                    }else{
                        break;
                    }  
                }
                //place the data in right place
                data[j] = tmp;
            }
        }
    }
    /**
     * merger sort originate from [DataStruct and Algorithms in C 2nd Edition]
     * always in middle split the data into two parts and merge into one with defined comparing,
    **/
    void mergerSort(vector<T>& data){
        vector<T> tmp(data.size()); //tmp data for store the sorted sequence
        merger2Sort(data, tmp, 0, data.size() - 1);
    }
    //merger sort recurse
    void merger2Sort(vector<T>& data, vector<T>& tmp, int left, int right){
        int mid;
        if(left < right){
            mid = (left + right) / 2;
            //split the data in index mid, and sort two part
            merger2Sort(data, tmp, left, mid);
            merger2Sort(data, tmp, mid + 1, right);
            //after the sort, merger two parts into one
            merger(data, tmp, left, mid + 1, right);
        }
    }
    void merger(vector<T>& data, vector<T>& tmp, int leftPos, int rightPos, int rightEnd){
        int leftEnd, nums, tmpPos;
        leftEnd = rightPos - 1;//left end
        tmpPos = leftPos; //tmp start pos
        nums = rightEnd - leftPos + 1; // the number of the data
        //merge two part as one
        while(leftPos <= leftEnd && rightPos <= rightEnd){
            if(data[leftPos] <= data[rightPos]){
                tmp[tmpPos++] = data[leftPos++]; 
            }else{
                tmp[tmpPos++] = data[rightPos++];
            }
        }
        //merge the rest of data
        //if the left part has the remain data
        while(leftPos <= leftEnd){
            tmp[tmpPos++] = data[leftPos++];
        }
        //or right part has the remain data
        while(rightPos <= rightEnd){
            tmp[tmpPos++] = data[rightPos++];
        }
        //copy the tmp sorted data to origin data
        for(int i = 0; i < nums; i++, rightEnd--){
            data[rightEnd] = tmp[rightEnd];
        }
    }
};

int main()
{
    sortsAlgo<int> algo;
	vector<int> data{0,-5,3,60,9,88,52,61,37,44};
	algo.mergerSort(data);
	for(auto d : data){
        std::cout << d << " ";
    }
	std::cout<<std::endl;
	return 0;
}