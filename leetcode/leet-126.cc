#include <vector>
#include <string>
#include <unordered_map>
#include<queue>
using std::queue;
using std::unordered_map;
using std::vector;
using std::string;

//leetcode official solution to learning
const int INF = 1 << 20;
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
        vector<int> cost(id, INF);
        
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
        for(int i = 0; i< idWord.size(); i++){
            for(int j = i + 1; j < idWord.size(); j++){
                if(transformCheck(idWord[i], idWord[j])){
                    edges[i].push_back(i);
                    edges[j].push_back(j);
                }
            }
        }

        const int dest = wordId[endWord];
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while(!q.empty()){
            vector<int> now = q.front();
            q.pop();

            int last = now.back();
            if(last == dest){
                vector<string> tmp;
                for(int index : now){
                    tmp.push_back(idWord[index]);
                }
                ret.push_back(tmp);
            }else{
                for(int i = 0; i < edges[last].size(); i++){
                    int to = edges[last][i];
                    if(cost[last] + 1 <= cost[to]){
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
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