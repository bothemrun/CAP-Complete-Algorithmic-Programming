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
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));

        for(int i=1;i+1<n;i++)
            for(int j=1;j+1<n;j++){

                int& a = ans[i-1][j-1];

                for(int x=(-1);x<=1;x++)
                    for(int y=(-1);y<=1;y++){
                        a = max(
                            a,
                            grid[i+x][j+y]
                        );
                    }
            }
        return ans;
    }
};
