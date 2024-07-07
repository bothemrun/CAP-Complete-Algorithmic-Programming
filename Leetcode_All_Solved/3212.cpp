//O(n) space instead of O(mn) extra space

//for possible cache locality, replace memo[2*2][n] with memo[n][2*2]
#define Memo_assign(i, j, c) ( memo[j][ ( (i)%2 + 2 )%2 ][c] )
#define Memo(i, j, c) ( (j>=0)? Memo_assign(i, j, c):0 )

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid.back().size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(2, 0) ));
        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char g = grid[i][j];

                Memo_assign(i, j, 0) = Memo(i-1, j, 0) + Memo(i, j-1, 0) - Memo(i-1, j-1, 0);
                Memo_assign(i, j, 1) = Memo(i-1, j, 1) + Memo(i, j-1, 1) - Memo(i-1, j-1, 1);

                if(g == 'X'){
                    Memo_assign(i, j, 0)++;
                }else if(g == 'Y'){
                    Memo_assign(i, j, 1)++;
                }

                ans += Memo(i, j, 0) != 0 && Memo(i, j, 0) == Memo(i, j, 1);
            }
        }
        return ans;
    }
};
