#include<algorithm>
#include<queue>
#include<limits.h>
class Solution {
public:
    inline void bfs(const vector<int>& edges, const int& node, vector<int>& dist){
        queue<int> q;
        q.push(node);
        dist[node] = 0;
        //int level = 0;

        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int cur = q.front();
                q.pop();

                if(edges[cur] != (-1)){

                    //NOTE: instack or bigger loop
                    //if(dist[edges[cur]] == INT_MAX)
                    if(dist[cur] + 1 >= dist[edges[cur]])
                        continue;

                    dist[edges[cur]] = dist[cur] + 1;
                    q.push(edges[cur]);
                }
            }

            //level++;
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        int minmax_dist = INT_MAX;
        int ans_idx = (-1);
        for(int i=0;i<n;i++)if(dist1[i] != INT_MAX && dist2[i] != INT_MAX){
            if(minmax_dist > max(dist1[i], dist2[i]) ){
                minmax_dist = max(dist1[i], dist2[i]);
                ans_idx = i;
            }
        }
        
        return ans_idx;
    }
};
