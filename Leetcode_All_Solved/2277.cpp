//great problem. used 3 techniques, 2 advanced tech.
//NOTE: tech: 
//(1) tree given by undirected edges & no root
//(2) lowest common ancestor
//(3) bfs

//O(Q * n), O(n) for finding lowest common ancestor & bfs.

#define max_n 1000
#include<queue>
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
    int n;
    vector<vector<int>> al;

    int lca_postorder(bool on_path[], const unordered_set<int>& lca_set, const int& u, const int& parent=(-1)){
        
        int found = 0;
        for(const int& v: al[u])if(v != parent){
            int found_sub = lca_postorder(on_path, lca_set, v, u);

            //NOTE: the lowest common ancestor already found, do nothing.
            if(found_sub == lca_set.size()) return lca_set.size();

            found += found_sub;
        }

        found += lca_set.count(u) != 0;

        if(found != 0) on_path[u] = true;

        return found;
    }

    int bfs(const bool on_path[], const int& src){
        queue<int> q;
        bool inq[max_n] = {0};//fast init to 0 by array

        q.push(src);
        inq[src] = true;

        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                if(on_path[u]) return u;


                for(const int& v: al[u])if(inq[v] == false){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }

        assert(false);
        return (-1);
    }

    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        this->n = n;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        int qsize = query.size();
        vector<int> ans(qsize);

        for(int i=0;i<qsize;i++){
            //1. find lca
            bool on_path[max_n] = {0};//fast init to 0 by array.
            unordered_set<int> lca_set( { query[i][0], query[i][1] } );
            //NOTE: any node can be the root
            lca_postorder(on_path, lca_set, 0);

            //2. bfs
            ans[i] = bfs(on_path, query[i][2] );
        }

        return ans;
    }
};
