#include<iostream>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.back().size();
        int max_cnt1 = 0, max_idx = 0;
        for(int i=0;i<m;i++){
            int cnt1 = 0;
            for(int j=0;j<n;j++)if(mat[i][j]) cnt1++;
            if(cnt1 > max_cnt1){
                max_cnt1 = cnt1;
                max_idx = i;
            }
        }
        return vector<int>({max_idx, max_cnt1});
    }
};
