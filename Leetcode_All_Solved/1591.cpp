//think of color as graph nodes, not cells as graph nodes.
//then it's a dag problem.
#define max_n 60
#define max_color 60
#include<limits.h>
#include<queue>

class Solution {
public:
    inline bool dag(const vector<vector<int>>& al, vector<int>& indegree){
        //1-indexed, but ok with index 0
        queue<int> q;
        int n = indegree.size();
        for(int i=0;i<n;i++)if(indegree[i] == 0)
            q.push(i);
        
        int topo_cnt = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                topo_cnt++;

                for(const int& v: al[u])if(--indegree[v] == 0)
                    q.push(v);
            }
        }

        return topo_cnt == n;
    }

    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size();
        int n = targetGrid.back().size();

        //1-indexed
        vector<vector<int>> color_al(max_color + 1);
        vector<int> indegree(max_color + 1, 0);

        for(int color=1;color<=max_color;color++){
            //1. find rectangular sides
            int minx = INT_MAX, maxx = INT_MIN;
            int miny = INT_MAX, maxy = INT_MIN;
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)if(targetGrid[i][j] == color){
                    minx = min(minx, i);
                    maxx = max(maxx, i);

                    miny = min(miny, j);
                    maxy = max(maxy, j);
                }
            
            //2. find other colors covering this color
            for(int i=minx;i<=maxx;i++)
                for(int j=miny;j<=maxy;j++)if(targetGrid[i][j] != color){
                    color_al[ color ].push_back( targetGrid[i][j] );
                    indegree[ targetGrid[i][j] ]++;
                }
        }

        return dag(color_al, indegree);
    }
};
