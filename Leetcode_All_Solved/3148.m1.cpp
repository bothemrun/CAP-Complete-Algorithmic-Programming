//m1

//O(m*n) time.
//cache optimization for matrix traversal.
//O(n) extra space optimization for dp.

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

        const int impossible = INT_MIN;
        //trap: can't init ans = 0
        int ans = impossible;

        vector<int> col_suffix_max(n, impossible);
        for(int i=m-1;i>=0;i--){
            //NOTE: not just row suffix max, but includes all suffix columns.
            int sub_suffix_max = impossible;

            for(int j=n-1;j>=0;j--){
                int cur = max(
                    col_suffix_max[j],
                    sub_suffix_max
                );

                if(cur != impossible) ans = max(ans, cur - grid[i][j] );

                //update
                col_suffix_max[j] = max(
                    col_suffix_max[j],
                    grid[i][j]
                );

                sub_suffix_max = max(
                    sub_suffix_max,
                    col_suffix_max[j]
                );
            }
        }

        return ans;
    }
};
