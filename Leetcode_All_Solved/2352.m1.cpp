//m1
//c++ map can have vector as keys, while unordered_map can't.
#include<map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> row2cnt;
        for(int i=0;i<n;i++)
            row2cnt[ grid[i] ]++;
        
        int cnt = 0;
        vector<int> col(n);
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++)
                col[i] = grid[i][j];
            
            //NOTE: inserts (key, 0) if not exist
            cnt += row2cnt[ col ];
        }

        return cnt;
    }
};
