//m0
//disjoint set union

//NOTE: pruning by trying to set union a cell's right & bottom neighbors.

//NOTE: pruning by maintaining the max cnt for the dsu, without enumerating all of dsu at the end.

#define IDX(i, j) (i*n + j)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<int> di = {1, 0};
    vector<int> dj = {0, 1};

    vector<int> dsu;
    vector<int> rank;

    vector<int> cnt;
    int max_cnt = 0;

    inline void make_set(int size, const vector<vector<int>>& grid){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size, 1);

        cnt.resize(size);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cnt[ IDX(i, j) ] = grid[i][j];
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a==b) return;

        if(rank[a] < rank[b]){
            dsu[a] = b;
            cnt[b] += cnt[a];

            max_cnt = max(max_cnt, cnt[b] );
        }else if(rank[a] > rank[b]){
            dsu[b] = a;
            cnt[a] += cnt[b];

            max_cnt = max(max_cnt, cnt[a] );
        }else{
            dsu[a] = b;
            cnt[b] += cnt[a];
            rank[b]++;

            max_cnt = max(max_cnt, cnt[b] );
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        make_set(m*n, grid);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] > 0){
                //NOTE: edge for the pruning: max_cnt
                max_cnt = max(max_cnt, grid[i][j] );


                for(int k=0;k<di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(grid[x][y] == 0) continue;

                    set_join( IDX(i, j), IDX(x, y) );
                }
            }
        
        return max_cnt;
    }
};
