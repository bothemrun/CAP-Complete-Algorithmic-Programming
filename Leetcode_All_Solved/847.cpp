//m0
//basically use level-order enumeration.

//NOTE: why use (node, visited mask) to avoid infinite cycle / repetition?
//NOTE: yes, both may have different previous paths to this node & mask,
//NOTE: but the "future state", or what we have now for the future is the same.
//NOTE: that is, we have the same starting point now for the future.
//NOTE: but the first path to visit the state (node, mask) has shorter  distance,
//NOTE: which is guaranteed by bfs.

#define PII pair<int,int>
#define max_n 12
#define max_mask (1<<12)
#include<queue>
#include<utility>
#include<assert.h>


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask_target = (1<<n) - 1;

        queue< PII > q;
        bool inq[max_n][max_mask] = {0};//NOTE: fast init to 0 by array

        for(int i=0;i<n;i++){
            int mask = (1<<i);
            q.push( PII(i, mask) );

            inq[i][mask] = true;
        }

        
        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                auto [u, mask_u] = q.front();
                q.pop();

                if(mask_u == mask_target) return level;

                for(const int& v: graph[u]){
                    int mask_v = ( mask_u | (1<<v) );
                    if(inq[v][mask_v]) continue;

                    q.push( PII(v, mask_v) );
                    inq[v][mask_v] = true;
                }
            }

            level++;
        }

        //since the graph is connected.
        assert(false);
        return (-1);
    }
};
