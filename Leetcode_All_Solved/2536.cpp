//m0
//2D difference array template

#define arr2(i, j) ( (i>=0 && j>=0)? arr[i][j]:0 )

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<vector<int>> diff;//no overflow

    inline void init(int m, int n){
        this->m = m;
        this->n = n;
        //must m+1
        diff.resize(m+1, vector<int>(n+1, 0) );
    }

    inline void range_update(int r1, int c1, int r2, int c2, int val){
        diff[r1][c1] += val;
        diff[r1][c2+1] -= val;
        diff[r2+1][c1] -= val;
        diff[r2+1][c2+1] += val;
    }

    inline void compute_diff(vector<vector<int>>& arr){
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                arr[i][j] = (
                    diff[i][j]
                    - arr2(i-1, j-1)
                    + arr2(i-1, j)
                    + arr2(i, j-1)
                );
            }
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        init(n, n);

        for(const vector<int>& q: queries){
            range_update(q[0], q[1], q[2], q[3], 1);
        }

        vector<vector<int>> arr(n, vector<int>(n));
        compute_diff(arr);
        return arr;
    }
};
