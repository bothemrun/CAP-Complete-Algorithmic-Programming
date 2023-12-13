#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.back().size();
        
        vector<int> row_cnt(m, 0);
        vector<int> col_cnt(n, 0);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(mat[i][j] == 1){
                row_cnt[i]++;
                col_cnt[j]++;
            }
        
        int ans = 0;
        for(int i=0;i<m;i++){
            //pruning
            if(row_cnt[i] != 1) continue;

            for(int j=0;j<n;j++)
                if(mat[i][j] == 1 && col_cnt[j] == 1){
                    ans++;
                    //pruning
                    break;
                }
        }
        
        return ans;
    }
};
