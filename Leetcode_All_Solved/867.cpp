#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();      
        vector<vector<int>> trans(n, vector<int>(m));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                trans[j][i] = matrix[i][j];
        return trans;
    }
};
