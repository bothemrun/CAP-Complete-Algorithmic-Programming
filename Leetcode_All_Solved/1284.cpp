//m0
//observation: if the flips of the 1st row is determined, 
//then its lower next row is also uniquely determined.
//since a cell of the next lower row can only influence the cell above it for cells in the 1st row.

//O(all possible flips of first row * duduce the remaining lower rows) = O(2^n * mn)

#include<limits.h>

class Solution {
public:
    int m, n;
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    int min_flip = INT_MAX;

    inline void flip(vector<vector<int>>& mat, const int& i, const int& j){
        mat[i][j] ^= 1;

        for(int k=0;k<di.size();k++){
            int x = i + di[k];
            int y = j + dj[k];
            if(!(0<=x && x<m && 0<=y && y<n)) continue;
            
            mat[x][y] ^= 1;
        }
    }

    void deduce_lower_rows(vector<vector<int>> mat, int flip_cnt){
        //mat is passed by value.
        //copy it in O(mn), same as O(mn) below

        //pruning
        if(flip_cnt >= min_flip) return;

        //flip for the upper row
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i-1][j] == 1){
                    flip(mat, i, j);

                    flip_cnt++;
                }
            }
        }

        //check last row
        for(int j=0;j<n;j++)if(mat[m-1][j] == 1)
            return;
        
        min_flip = min(min_flip, flip_cnt);
    }

    void enum_first_row(vector<vector<int>>& mat, const int& j, int flip_cnt){
        if(j==n){
            deduce_lower_rows(mat, flip_cnt);
            return;
        }

        //choose or not choose
        enum_first_row(mat, j+1, flip_cnt);

        flip(mat, 0, j);
        enum_first_row(mat, j+1, flip_cnt + 1);
        flip(mat, 0, j);
    }

    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat.back().size();

        enum_first_row(mat, 0, 0);
        
        return (min_flip==INT_MAX)? (-1):min_flip;
    }
};
