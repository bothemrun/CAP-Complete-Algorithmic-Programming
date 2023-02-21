#include<utility>
class Solution {
public:
    int m, n;
    vector<vector<pair<int,int>>> set;
    const pair<int,int> root = {-1, -1};
    vector<vector<bool>> side = {
        {},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 1, 1, 0}
    };
    vector<int> di = {1, 0};
    vector<int> dj = {0, 1};

    pair<int,int> set_find(const pair<int,int>& a){
        if(set[a.first][a.second] == root)return a;
        return set[a.first][a.second] = set_find(set[a.first][a.second]);
    }

    void set_join(pair<int,int> a, pair<int,int> b){
        a = set_find(a);
        b = set_find(b);
        if(a != b) set[a.first][a.second] = b;
        //NOTE: if a b same root, and a is the root
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();
        set = vector<vector<pair<int,int>>>( m, vector<pair<int,int>>(n, root) );

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                for(int d=0;d<2;d++){
                    int x = i + di[d];
                    int y = j + dj[d];
                    if(!(0<=x && x<m && 0<=y && y<n))continue;

                    if( side[ grid[i][j] ][d] &&
                    side[ grid[x][y] ][ (d+2)%4 ] )
                        set_join(pair<int,int>(i, j), pair<int,int>(x, y) );
                }
        
        return set_find(pair<int,int>(0, 0)) == set_find(pair<int,int>(m-1, n-1));;
    }
};
