//m1
//topological sort by onion peeling / bfs
//strict monotone forms a topological sort, dependency and sub-structures.
#define mod ((int)1e9 + 7)
#define MOD(x) ( (x >= mod)? (x-mod):x )
#define IDX(i, j) ( (i)*n + j )

#include<queue>
#include<tuple>
#include<iostream>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<vector<tuple<int,int>>> adj(m*n);
        vector<int> indegree(m*n, 0);

        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<di.size();k++){
                int x = i+di[k];
                int y = j+dj[k];
                if(0<=x && x<m && 0<=y && y<n && grid[i][j] < grid[x][y] ){
                    adj[ IDX(i, j) ].push_back( tuple<int,int>(x, y) );
                    indegree[ IDX(x, y) ]++;
                }
            }

        
        int all_cnt = 0;
        vector<int> memo(m*n, 1);

        //topological sort by onion peeling / bfs
        queue<tuple<int,int>> q;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)if(indegree[ IDX(i, j) ] == 0)
            q.push( tuple<int,int>(i, j) );

        while(q.size() != 0){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                auto [i, j] = q.front();
                q.pop();
                all_cnt = MOD( all_cnt + memo[ IDX(i, j) ] );

                for(auto [x, y]: adj[ IDX(i, j) ] ){
                    memo[ IDX(x, y) ] = MOD( memo[ IDX(x, y) ] + memo[ IDX(i, j) ] );
                    if(--indegree[ IDX(x, y) ] == 0)
                        q.push( tuple<int,int>(x, y) );
                }
            }
        }

        return all_cnt;
    }
};
