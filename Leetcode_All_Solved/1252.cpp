//let indices.size() := I

//instead of O(I * max(m, n)) + O(m*n) with O(m*n) extra space,

//follwo-up: O(I) + O(m + n) with O(m+n) extra space.

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<bool> row_par(m, false);
        vector<bool> col_par(n, false);

        for(const vector<int>& i: indices){
            row_par[i[0]] = (true ^ row_par[i[0]]);
            col_par[i[1]] = (true ^ col_par[i[1]]);
        }

        int col_par_cnt = 0;
        for(bool par: col_par)
            col_par_cnt += par;
        
        int ans = 0;
        for(bool par: row_par){
            if(par) ans += n - col_par_cnt;
            else ans += col_par_cnt;
        }

        return ans;
    }
};
