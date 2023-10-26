//m1
//code optim from m0 5% runtime.

//Thinking Process:

//[A] why not the standard undirected cycle detection dfs?
//1. that dfs is not for the "real" circle cycle.
//2. counterexample: 2 real circle cycles connected by 1 chain.

//[B] counterexamples:
//1. real circle cycles need "going back to the start node"
//2. edge case: two circle cycles share some segment.

//[C] Circle Detect:
//1. cut each edge u-v
//2. find shortest distance from u to v

//[D] dfs Solve [B].2 Case?
//1. the visited vector may be used by the longer circle first.
//2. so use BFS.


//[E] so why try every start node?
//1. the case in [B]

//O(n * E), E := edges.size()

#define maxn 1000
#include<queue>
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int n;
    vector<vector<int>> al;

    inline bool bfs_circle(const int& src, const int& dest, int& level){
        queue<int> q;
        bool inq[maxn] = {0};
        
        q.push(src);
        inq[src] = true;

        level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                if(u == dest) return true;


                for(const int& v: al[u])if(inq[v] == false && !(
                    (u==src && v==dest) ||
                    (v==src && u==dest)
                ) ){
                    inq[v] = true;
                    q.push(v);
                }
            }

            level++;
        }

        return false;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        this->n = n;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }


        int no_circle = INT_MAX;
        int min_circle = no_circle;

        for(const vector<int>& e: edges){
            int level;
            if(bfs_circle(e[0], e[1], level) == true)
                min_circle = min(min_circle, level + 1);
            //level >= 1
        }

        return (min_circle==no_circle)? (-1):min_circle;
    }
};
