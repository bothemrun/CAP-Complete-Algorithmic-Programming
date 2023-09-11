#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<int> ans(n, 1);

        //row-first iteration is faster.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int& x = grid[i][j];

                int len = (x < 0);
                while(x){
                    x /= 10;
                    len++;
                }

                ans[j] = max( ans[j], len );
            }
        }

        return ans;
    }
};
