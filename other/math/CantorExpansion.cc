#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
/**
 * rank = an*(n − 1)!+ an−1*(n − 2)!+ ⋯ +a1*0!
 * an represent the from index i to end, counter the less than data in index i
*/
class cantorExpansion{
public:
    cantorExpansion(){
        // 0 - 9 factorial
        factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    }

    int cantor(vector<int>& perm){
        int res = 0;
        int size = perm.size();
        if(size == 0){
            return -1;
        }

        for(int i = 0; i < size; i++){
            int count = 0;
            for(int j = i + 1; j < size; j++){
                if(perm[i] > perm[j]){
                    count++;
                }
            }
            res += count * factorial[size - 1 - i];
        }
        return res + 1;
    }

    vector<int> reverseCantor(vector<int>& array, int num){
        vector<int> ret;
        int size = array.size();
        if (num > factorial[size]){
            return ret;
        }
        num--; // the permulation map index start from 0  
        for(int i = 1; i <= size; i++){
            int idx = num / factorial[size - i];// how many data 
            num %= factorial[size - i];
            ret.push_back(array[idx]);
            array.erase(array.begin() + idx);
        }
        return ret;
    }

private:
    vector<int> factorial;
};

int main(int argc, char const *argv[])
{
    cantorExpansion cantor;
    vector<int> array{1,2,3,4,5,6,7};
    vector<int> ret = cantor.reverseCantor(array, 5000);
    for(auto i : ret){
        cout <<" " << i ;
    }
    cout<<endl;
    cout << " num = " << cantor.cantor(ret);
    cout <<endl;
    return 0;
}
