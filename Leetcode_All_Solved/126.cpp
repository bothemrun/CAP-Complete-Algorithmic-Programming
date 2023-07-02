//m0
//(uni-directional) bfs

//NOTE: backtracking in reverse allows us to track only the shortest paths,
//while forward tracing has lots of non-shortest paths.

//NOTE: multiple paths to the same node in the same shortest distance:

//1. can't enqueue later after this level,

//'cuz we can't prevent pushing the same node of diffferent previous paths for multiple times.
//but we still need to record all the parents of the node.

//2. so we use a distance vector, 

//if trying to push the same node at the same level/distance,
//we just record the parents without enqueue.



//NOTE: optim by only handling the indices, not the actual strings.

//NOTE: no parallel edges, since connectivity must differ by 1 char.

#define wildcard '*'
#include<unordered_map>
#include<queue>
#include<limits.h>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, len;
    int begin_i, end_i;

    inline void wildcard2word(const vector<string>& wordList, unordered_map<string, vector<int>>& star2word){

        for(int i=0;i<n;i++){
            const string& word = wordList[i];

            for(int j=0;j<len;j++){
                string star = word;
                star[j] = wildcard;

                star2word[star].push_back(i);
            }
        }
    }

    inline bool find_idx(vector<string>& wordList, const string& beginWord, const string& endWord){

        end_i = (-1);
        begin_i = (-1);
        for(int i=0;i<n;i++){
            if(wordList[i] == endWord) end_i = i;
            if(wordList[i] == beginWord) begin_i = i; 
        }
        //NOTE: edge: no start for backtracking
        if(end_i==(-1)) return false;

        //for bfs referencing
        if(begin_i==(-1)){
            wordList.push_back(beginWord);
            n = wordList.size();

            begin_i = n-1;
        }

        return true;
    }

    inline bool bfs_parent_dist(const vector<string>& wordList, unordered_map<string, vector<int>>& star2word, vector<vector<int>>& parent_list){

        queue<int> q;

        //NOTE: the same node of the same distance level & different paths.
        vector<int> dist(n, INT_MAX);

        q.push(begin_i);
        dist[begin_i] = 1;
        int level = 1;

        bool found_shortest = false;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int u = q.front();
                q.pop();

                if(u == end_i) found_shortest = true;


                const string& word = wordList[u];
                for(int j=0;j<len;j++){
                    string star = word;
                    star[j] = wildcard;

                    for(const int& v: star2word[star]){
                        if(dist[u] + 1 < dist[v]){
                            dist[v] = dist[u] + 1;
                            assert(parent_list[v].size() == 0);
                            q.push(v);

                            parent_list[v].push_back(u);
                        }else if(dist[u] + 1 == dist[v]){
                            //NOTE: same node with different paths & same level, don't enqueue
                            parent_list[v].push_back(u);
                        }
                    }
                }
            }

            if(found_shortest) break;

            level++;
        }

        return found_shortest;
    }

    vector<vector<string>> ans;
    inline void make_path(const vector<string>& wordList, const vector<int>& path1){

        vector<string> res;
        int size = path1.size();
        for(int i=size-1;i>=0;i--)
            res.push_back(wordList[ path1[i] ]);
        ans.push_back(res);
    }

    inline void backtrack(vector<int>& path1, const vector<vector<int>>& parent_list, const int& v, const vector<string>& wordList){

        path1.push_back(v);

        if(parent_list[v].size() == 0){
            assert(v == begin_i);
            
            make_path(wordList, path1);

            path1.pop_back();
            return;
        }

        
        for(const int& u: parent_list[v])
            backtrack(path1, parent_list, u, wordList);
        path1.pop_back();
    }

    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        len = wordList.back().size();

        unordered_map<string, vector<int>> star2word;
        wildcard2word(wordList, star2word);


        if( find_idx(wordList, beginWord, endWord) == false) return ans;


        vector<vector<int>> parent_list(n);
        if( bfs_parent_dist(wordList, star2word, parent_list) == false) return ans;
        

        vector<int> path1;
        backtrack(path1, parent_list, end_i, wordList);
        return ans;
    }
};
