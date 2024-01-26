//O(mn * maxMove) = O(50^3) = 1e5
#define notyet (-1)
#define mod ((int)1e9 + 7)
#include<assert.h>

class Solution {
public:
    vector<vector<vector<int>>> memo;
    int m, n;
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    int enum_grid(const int& move, const int& r, const int& c){

        if(!(0<=r && r<m && 0<=c && c<n)) return 1;
        if(move==0) return 0;
        assert(move > 0);

        if(memo[move][r][c] != notyet) return memo[move][r][c];

        int path = 0;
        for(int k=0;k<di.size();k++){
            path = (
                path +
                enum_grid(move-1, r+di[k], c+dj[k] )
            )%mod;
        }

        return memo[move][r][c] = path;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memo.resize(maxMove+1, vector<vector<int>>(m, vector<int>(n, notyet)) );
        this->m = m;
        this->n = n;

        return enum_grid(maxMove, startRow, startColumn);
    }
};
