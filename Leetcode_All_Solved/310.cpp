//m0

//1. topological sort distances to leaves

//2. but when to stop the while loop?

//3. are the final MHT roots connected?
//3.a. yes. otherwise the nodes on the path connecting those 2 roots have less heights.

//4. how many roots?
//4.a. since it's a tree, all connected roots must lie in an acyclic line.
//4.b. so if the number of roots >= 3, then topological sort still can continue.
//4.c. except for roots <= 2.

//5. O(n)

//6. this method is tricky. the most tricky point is to come up with roots <= 2

//7. so I'd rather use rerooting, dp on trees.

#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> al(n);
        vector<int> indegree(n, 0);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);

            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        vector<bool> ever2q(n, false);
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i] == 1){
            q.push(i);
            ever2q[i] = true;
        }

        vector<bool> popped(n, false);
        int unpopped = n;

        while(unpopped > 2){
            int qsize = q.size();
            assert(qsize);
            for(int l=0;l<qsize;l++){
                int u = q.front();
                q.pop();

                popped[u] = true;
                unpopped--;


                for(const int& v: al[u])if(ever2q[v] == false){
                    if(--indegree[v] == 1){
                        q.push(v);
                        ever2q[v] = true;
                    }
                }
            }
        }

        vector<int> centroid;
        for(int i=0;i<n;i++)if(popped[i] == false){
            centroid.push_back(i);
        }
        assert(1<=centroid.size() && centroid.size()<=2);
        return centroid;
    }
};
