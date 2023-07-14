//O(mnlogn + nmlogm) for sorting, then O(mn) for topological sort.

#define max_n 1000
#define PII pair<int,int>
#include<queue>
#include<utility>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};


        vector<vector< vector< PII > >> al(m, vector< vector< PII > >(n) );
        int indegree[max_n][max_n] = {0};

        auto cmp_fn = [](const PII& a, const PII& b){
            return a.first < b.first;
        };

        for(int i=0;i<m;i++){
            vector<PII> val2idx(n);
            for(int j=0;j<n;j++) val2idx[j] = PII( grid[i][j], j );

            sort(val2idx.begin(), val2idx.end(), cmp_fn);

            for(int j=0;j<n-1;j++){
                PII from( i, val2idx[j].second );
                PII to( i, val2idx[j + 1].second );

                al[from.first][from.second].push_back(to);
                indegree[to.first][to.second]++;
            }
        }

        for(int j=0;j<n;j++){
            vector<PII> val2idx(m);
            for(int i=0;i<m;i++) val2idx[i] = PII( grid[i][j], i );

            sort(val2idx.begin(), val2idx.end(), cmp_fn);

            for(int i=0;i<m-1;i++){
                PII from( val2idx[i].second, j );
                PII to( val2idx[i+1].second, j );

                al[from.first][from.second].push_back(to);
                indegree[to.first][to.second]++;
            }
        }


        //topological sort by onion peeling
        queue<PII> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(indegree[i][j] == 0)
                q.push( PII(i, j) );

        int level = 1;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                auto [i, j] = q.front();
                q.pop();

                grid[i][j] = level;

                for(const auto& [x, y]: al[i][j] )if(--indegree[x][y] == 0)
                    q.push(PII(x, y));
            }

            level++;
        }

        return grid;
    }
};
