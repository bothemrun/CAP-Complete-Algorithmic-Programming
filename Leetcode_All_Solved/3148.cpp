//m0

//O(m*n) time.
//cache optimization for matrix traversal.

//the values in between the path are all cancelled.
//so we only need sub-matrix max.


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
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<vector<int>> sub_max(m, vector<int>(n));
        const int impossible = INT_MIN;
        //trap: can't init ans = 0
        int ans = impossible;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int bott = (i+1<m)? sub_max[i+1][j]:impossible;
                int right = (j+1<n)? sub_max[i][j+1]:impossible;

                if(max(bott, right) != impossible){
                    ans = max(
                        ans,
                        max(bott, right) - grid[i][j]
                    );
                }

                //update
                sub_max[i][j] = max({
                    grid[i][j],
                    bott,
                    right
                });
            }
        }

        return ans;
    }
};
