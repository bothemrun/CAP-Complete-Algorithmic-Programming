//m0
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

#include<queue>
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> al(n);
        for(vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);

            sort(e.begin(), e.end());
        }


        int no_circle = INT_MAX;
        int min_circle = no_circle;

        for(const vector<int>& e: edges){
            int level;

            auto bfs_circle = [&level, &al, &e, n](){
                queue<int> q;
                vector<bool> inq(n, false);

                q.push(e[0]);
                inq[e[0]] = true;

                level = 0;
                while(q.size()){
                    int lsize = q.size();
                    for(int l=0;l<lsize;l++){
                        int u = q.front();
                        q.pop();

                        if(u == e[1]) return true;


                        for(const int& v: al[u])if(inq[v] == false){
                            //NOTE: don't go to the cut edge
                            vector<int> e2 = {u, v};
                            sort(e2.begin(), e2.end());
                            if(e == e2) continue;

                            inq[v] = true;
                            q.push(v);
                        }
                    }

                    level++;
                }

                return false;
            };

            if(bfs_circle() == true){
                min_circle = min(min_circle, level + 1);
            }
        }

        return (min_circle==no_circle)? (-1):min_circle;
    }
};
