//m0
//(uni-directional) bfs

#define wildcard '*'
#include<queue>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int m = wordList.size();
        int n = wordList.back().size();

        unordered_map<string, vector<int>> star2word;
        for(int i=0;i<m;i++){
            const string& word = wordList[i];
            for(int j=0;j<n;j++){
                string star = word;
                star[j] = wildcard;

                star2word[star].push_back(i);
            }
        }


        int end_idx = (-1);
        for(int i=0;i<m;i++)if(wordList[i] == endWord){
            end_idx = i;
            break;
        }
        //edge
        if(end_idx == (-1)) return 0;

        //NOTE: add beginWord into wordList, but not into the star wildcard transition table
        wordList.push_back(beginWord);
        m = wordList.size();
        int begin_idx = m-1;

        queue<int> q;
        vector<bool> inq(m, false);

        q.push(begin_idx);
        inq[begin_idx] = true;

        int level = 1;//counts the beginning
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int u = q.front();
                q.pop();

                if(u == end_idx) return level;

                
                const string& word = wordList[u];
                for(int j=0;j<n;j++){
                    string star = word;
                    star[j] = wildcard;

                    for(const int& v: star2word[star]){
                        //NOTE: must differ by 1 char
                        if(word[j] == wordList[v][j]) continue;
                        if(inq[v]) continue;

                        q.push(v);
                        inq[v] = true;
                    }
                }
            }

            level++;
        }

        return 0;
    }
};
