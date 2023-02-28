//m1
//union by rank & path compression
#define IDX(i, j) (i*n + j)
#define ROOT (-1)
class Solution {
public:
    int m, n;
    vector<int> dx = {1, 0};
    vector<int> dy = {0, 1};
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& size){
        set = vector<int>(size, ROOT);
        rank = vector<int>(size, 0);
    }

    int set_find(const int& a){
        if(set[a] == ROOT)return a;
        return set[a] = set_find(set[a]);
    }

    inline bool set_join_same_set(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return true;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid.back().size();
        make_set(m*n);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                char c = grid[i][j];
                for(int k=0;k<dx.size();k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(!(0<=x && x<m && 0<=y && y<n))continue;
                    if(grid[x][y] != c)continue;

                    if(set_join_same_set(IDX(i, j), IDX(x, y) ) == true)return true;
                }
            }
        
        return false;
    }
};
