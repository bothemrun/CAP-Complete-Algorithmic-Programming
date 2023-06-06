#define delim ","
#include<unordered_map>
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
        unordered_map<string, int> row2cnt;
        int n = grid.size();
        for(int i=0;i<n;i++){
            string code = "";
            for(int j=0;j<n;j++)
                code += to_string(grid[i][j]) + delim;

            row2cnt[code]++;
        }

        int cnt = 0;
        for(int j=0;j<n;j++){
            string code = "";
            for(int i=0;i<n;i++)
                code += to_string(grid[i][j]) + delim;
            
            if(row2cnt.count(code) != 0)
                cnt += row2cnt[code];
        }

        return cnt;
    }
};
