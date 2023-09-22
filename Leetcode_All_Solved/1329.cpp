//O(mn * log( max(m, n) ))

#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;

    inline void read_dia(const vector<vector<int>>& mat, vector<int>& dia, int i, int j){
        while(i<m && j<n){
            dia.push_back( mat[i++][j++] );
        }
    }
    inline void write_dia(vector<vector<int>>& mat, const vector<int>& dia, int i, int j){
        for(int k=0;k<(int)dia.size();k++){
            assert(i<m && j<n);
            mat[i++][j++] = dia[k];
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat.back().size();

        for(int i=0;i<m;i++){
            vector<int> dia;
            read_dia(mat, dia, i, 0);

            sort(dia.begin(), dia.end());
            write_dia(mat, dia, i, 0);
        }

        for(int j=1;j<n;j++){
            vector<int> dia;
            read_dia(mat, dia, 0, j);

            sort(dia.begin(), dia.end());
            write_dia(mat, dia, 0, j);
        }

        return mat;
    }
};
