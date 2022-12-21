#include<utility>
class Solution {
public:
    vector<vector<pair<int,int>>> set;
    vector<vector<int>> set_cnt;
    int over2_cnt = 0;

    pair<int,int> set_find(const pair<int,int>& p){
        if(set[p.first][p.second].first == (-1))return p;
        return set[p.first][p.second] = set_find( set[p.first][p.second] );
    }
    inline void set_join(pair<int,int> a, pair<int,int> b){
        a = set_find(a);
        b = set_find(b);
        if(a != b){
            set[a.first][a.second] = b;
            //NOTE: for a is the root, and b is the child of a

            if(set_cnt[a.first][a.second] == 1) over2_cnt++;
            if(set_cnt[b.first][b.second] == 1)over2_cnt++;

            set_cnt[b.first][b.second] += set_cnt[a.first][a.second];

        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        set = vector<vector<pair<int,int>>>(m, vector<pair<int,int>>(n, pair<int,int>(-1,-1) ));
        set_cnt = vector<vector<int>>(m, vector<int>(n, 1));

        for(int i=0;i<m;i++){
            bool met_first = false;
            int first;
            for(int j=0;j<n;j++)if(grid[i][j] == 1){
                if(met_first == false){
                    met_first = true;
                    first = j;
                }else{
                    set_join(pair<int,int>(i, first), pair<int,int>(i, j));
                }
            }
        }

        for(int j=0;j<n;j++){
            bool met_first = false;
            int first;
            for(int i=0;i<m;i++)if(grid[i][j] == 1){
                if(met_first == false){
                    met_first = true;
                    first = i;
                }else{
                    set_join(pair<int,int>(first, j), pair<int,int>(i, j));
                }
            }
        }

        return over2_cnt;
    }
};

