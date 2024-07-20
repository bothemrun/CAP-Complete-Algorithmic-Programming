//m1
//constructive greedy

//[A] i & j are independent to each other.


//[B] Dimension Reduction:
//1. now for each row, we need to distribute rowSum[i] to some columns, without making any colSum[j] < 0.


//[C]
//1. use a max heap for online col sums in overall O(mnlogn)
//2. just a simple O(n) loop to subtract any col sum > 0 in overall O(mn).

//O(mn) time, O(1) extra space

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
                /*
                if(rowSum[i] > 0){
                    ans[i][j] = min(rowSum[i], colSum[j]);

                    rowSum[i] -= ans[i][j];
                    colSum[j] -= ans[i][j];
                }else{
                    ans[i][j] = 0;
                }
                */
            }
        }
        return ans;
    }
};
