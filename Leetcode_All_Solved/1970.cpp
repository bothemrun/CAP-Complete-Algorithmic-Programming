//m0
//use 2 dummy cells for the top & bottom rows.
//from all water to all land in reverse.
//connect the land cells

#define IDX(i, j) (n*i + j)
#define top_row (m*n)
#define bottom_row (m*n + 1)

#define dsu_size (m*n + 2)

#define water 1
#define land 0

#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    inline void make_set(int size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a==b) return;

        if(rank[a] < rank[b]) dsu[a] = b;
        else if(rank[a] > rank[b]) dsu[b] = a;
        else{
            dsu[a] = b;
            rank[b]++;
        }
    }
    

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int m = row;
        int n = col;
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};

        vector<vector<bool>> grid(m, vector<bool>(n, water) );
        make_set(dsu_size);

        assert(cells.size() == m*n);
        for(int day=m*n-1;day>=0;day--){
            //all to 0-indexed
            int i = cells[day][0] - 1;
            int j = cells[day][1] - 1;

            grid[i][j] = land;

            for(int k=0;k<di.size();k++){
                int x = i+di[k];
                int y = j+dj[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                if(grid[x][y] != land) continue;

                set_join( IDX(i, j), IDX(x, y) );
            }

            //NOTE: 2 dummy top / bottom row cells
            if(i==0) set_join( top_row, IDX(i, j) );
            if(i==m-1) set_join( bottom_row, IDX(i, j) );


            //check
            if( set_find(top_row) == set_find(bottom_row) )
                return day;
        }

        assert(false);
        return (-1);
    }
};
