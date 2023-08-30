//m1
//preprocessing: predecessor relationship forms an edge.
//byt their topological order, do a topological sort.
//O(NLL)

//they are acyclic and form a topological order,
//since the length difference must be 1.

#include<queue>
#include<unordered_map>

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        //also de-duplicate
        unordered_map<string, int> word2i;
        //if duplicate strings, then any index will do.
        for(int i=0;i<(int)words.size();i++)
            word2i[ words[i] ] = i;
        
        //for duplicate words, only 1 word will have possibly nonzero indegree
        int n = words.size();

        vector<vector<int>> al(n);
        vector<int> indegree(n, 0);
        for(const auto& [word, i]: word2i){
            for(int k=0;k<(int)word.size();k++){
                string pred = word.substr(0, k) + word.substr(k+1);
                if(word2i.count(pred) == 0) continue;

                int j = word2i[pred];

                al[i].push_back(j);
                indegree[j]++;
            }
        }


        //topological sort
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i] == 0)
            q.push(i);

        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int i = q.front();
                q.pop();

                for(const int& j: al[i])if(--indegree[j] == 0)
                    q.push(j);
            }

            level++;
        }

        return level;
    }
};
