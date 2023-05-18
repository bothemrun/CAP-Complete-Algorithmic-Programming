//m1
//topogogical sort by onion peeling / bfs
#define IDX(i, j) ((i)*n + j)
#include<queue>
#include<tuple>
class Solution {
public:
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();

        vector<vector<tuple<int,int>>> adj(m*n);
        vector<int> indegree(m*n, 0);
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<di.size();k++){
                int x = i+di[k];
                int y = j+dj[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                if(!(matrix[i][j] < matrix[x][y] ) ) continue;
                indegree[ IDX(x, y) ]++;
                adj[ IDX(i, j) ].push_back( tuple<int,int>(x, y) );
            }
        
        //NOTE: topological sort by onion peeling / bfs
        queue<tuple<int,int>> q;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)if(indegree[ IDX(i, j) ] == 0)
            q.push( tuple<int,int>(i, j) );
        int level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                auto [i, j] = q.front();
                q.pop();

                for(auto [x, y]: adj[ IDX(i, j) ]){
                    if(--indegree[ IDX(x, y) ] == 0) q.push( tuple<int,int>(x, y) );
                }
            }

            level++;
        }

        return level;
    }
};
