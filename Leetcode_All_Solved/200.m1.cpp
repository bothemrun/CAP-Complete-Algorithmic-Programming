//m1
//union by rank & path compression, amortized O(1)
#define IDX(i, j) ( n*i + j )
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    inline void make_set(const int& size, const vector<vector<char>>& grid){
        set = vector<int>(size, -1);
        rank = vector<int>(size, 0);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == '0'){
                set[IDX(i, j)] = -2;
            }
    }

    int set_find(const int& a){
        if(set[a] == -1)return a;
        return set[a] = set_find(set[a]);
    }

    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
    }

    inline int set_count(){
        int cnt = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(set[ IDX(i, j) ] == -1) cnt++;
        return cnt;
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid.back().size();
        make_set(m*n, grid);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == '1'){
                for(int k=0;k<dx.size();k++){
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(grid[x][y] == '0') continue;

                    set_join(
                        IDX(i, j),
                        IDX(x, y)
                    );
                }
            }
        
        return set_count();
    }
};
