static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        vector<vector<int>> ans;
        if(size != m*n) return ans;

        ans.resize(m, vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans[i][j] = original[i*n + j];
        return ans;
    }
};
