#include<vector>
#include <iostream>
#include <climits>
using std::vector;
using std::swap;

template<typename T>
class priorityQueue{
public:
    inline int left(int i){
        return 2 * i + 1;
    }
    inline int right(int i){
        return 2 * i + 2;
    }
    inline int parent(int i){
        return i / 2;
    }
    /***solution from Introduction of algorithm 3rd Edition***/
    void maxHeapify(vector<T>& array, int i, int size){
        int l = left(i);
        int r = right(i);
        int largest;

        if(l < size and array[l] > array[i]){
            largest = l;
        }else{
            largest = i;
        }
        if(r < size and array[r] > array[largest]){
            largest = r;
        }
        
        if(largest != i){
            swap(array[i], array[largest]);
            maxHeapify(array, largest, size);
        }
    }

    void builMaxHeap(vector<T>& arrray){
        int size = arrray.size();
        for(int i = size / 2; i >= 0; i--){
            maxHeapify(arrray, i, size);
        }
    }

    T heapMaximun(vector<T>& array){
        return array[0];
    }

    T heapExtractMax(vector<T>& array){
        if(array.size() < 0){
            throw("Overflow");
        }
        T max = array[0];
        array[0] = array[array.size() - 1];
        array.pop_back();
        maxHeapify(array, 0, array.size());
        return max;
    }

    void heapIncrease(vector<T>& array, int i, T key){
        if(key < array[i]){
            return;
        }

        array[i] = key;
        while(i > 0 && array[parent(i)] < array[i]){
            swap(array[i],  array[parent(i)]);
            i = parent(i);
        }
    }

    void maxHeapInsert(vector<T>& array, T key){;
        array.push_back((T)INT_MIN);
        heapIncrease(array, array.size() - 1, key);
    }

    bool empty(vector<T> array){
        return array.empty();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    priorityQueue<int> queue;
    vector<int> nums{ 23, 45, 12, 90, 18, 675, 64, 543, 89, 94};
    queue.builMaxHeap(nums);
    /* delete and build the max heap
    while(!queue.empty(nums)){
        std::cout << queue.heapExtractMax(nums)<< std::endl;
    }*/

    vector<int> heap{ 23, -7, 45, 12, 90, 42, 18, 75, 81};
    vector<int> insert{57, 66, 93, 78, 104, 14, 18, 258, 89, 394};
    queue.builMaxHeap(heap);
    for(int i = 0; i < insert.size(); i++){ 
        //insert and build heap
        queue.maxHeapInsert(heap, insert[i]);
        queue.builMaxHeap(heap);
        std::cout <<"max = " << queue.heapMaximun(heap)<< std::endl;
        /*
        for(auto h : heap){
            std::cout << h << " ";
        }
        std::cout<< std::endl;
        */
    }
    return 0;
}
