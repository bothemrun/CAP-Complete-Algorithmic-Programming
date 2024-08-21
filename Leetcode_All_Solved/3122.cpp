//O(m*n + 10*n) dp
#define max_val 9
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<vector<int>> col2val2cnt;

    const int notyet = (-1);
    vector<vector<int>> memo;

    int enum_col_val(int col, int val){
        if(col == n-1) return m - col2val2cnt[col][val];

        if(memo[col][val] != notyet) return memo[col][val];

        int ret = INT_MAX;
        //enum next col's val
        for(int next_val=0;next_val<=max_val;next_val++)if(next_val != val){
            ret = min(
                ret,
                enum_col_val(col+1, next_val)
            );
        }

        return memo[col][val] = (m - col2val2cnt[col][val] ) + ret;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();
        col2val2cnt.resize(n, vector<int>(max_val + 1, 0));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                col2val2cnt[j][ grid[i][j] ]++;
        
        memo.resize(n, vector<int>(max_val + 1, notyet));
        int ans = INT_MAX;
        for(int val0=0;val0<=max_val;val0++){
            ans = min(
                ans,
                enum_col_val(0, val0)
            );
        }
        return ans;
    }
};
