#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>

using std::queue;
using std::unordered_map;
using std::vector;
using std::string;

//leetcode official solution to learning
class Solution {
private:
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        vector<vector<string>> ret;
        queue<vector<int>> q;
        
        for(const string& word : wordList){
            //calculate the unique word in word list
            if(!wordId.count(word)){
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        //if the end word is not exist, impossible work
        if(!wordId.count(endWord)){
            return {};
        }
        //checke if the begin word exist, if not exist, add it
        if(!wordId.count(beginWord)){
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        //resize the edges
        edges.resize(idWord.size());
        //build the edges in id word list
        for(int i = 0; i < idWord.size(); i++){
            for(int j = i + 1; j < idWord.size(); j++){
                if(transformCheck(idWord[i], idWord[j])){
                    //i -> j ; j-> i
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        //mark the dest id
        const int dest = wordId[endWord];
        vector<int> cost(id, INT_MAX); // cost record the size from begin to id-string
        q.push(vector<int>{wordId[beginWord]}); // add the begin word to queue
        cost[wordId[beginWord]] = 0; // mark the distance from begin to current word
        while(!q.empty()){
            vector<int> now = q.front();
            q.pop();
            //check the last index whether is the destine index
            int last = now.back();
            if(last == dest){
                vector<string> tmp;
                for(int index : now){
                    //push the all index string to tmp
                    tmp.push_back(idWord[index]);
                }
                ret.push_back(tmp);
            }else{
                //serch the matrix in the row [last] 
                for(int i = 0; i < edges[last].size(); i++){
                    int to = edges[last][i]; //distance from last to i
                    //and check if the distance
                    if(cost[last] + 1 <= cost[to]){
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);//rebuild the tmp base the now
                        tmp.push_back(to); //find the path add it 
                        q.push(tmp); //record it
                    }
                }
            }
        }

        return ret;
    }

    bool transformCheck(const string& str1, const string& str2){
        int differences = 0;
        for(int i = 0; i < str1.size() && differences < 2; i++){
            if(str1[i] != str2[i]){
                differences++;
            }
        }

        return differences == 1;
    }
};