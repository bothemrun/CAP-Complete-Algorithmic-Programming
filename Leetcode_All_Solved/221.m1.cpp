//m1
//recursion with memo, by tuple
#include<algorithm>
#include<tuple>
#define Tu3 tuple<int,int,int>
#define notyet (Tu3(-1, -1, -1))

class Solution {
public:
    //(square, height, leftward width)
    vector<vector<Tu3>> memo;
    int max_square = 0;

    Tu3 bottom_right(const vector<vector<char>>& matrix, const int& i, const int& j){
        if(i<0 || j<0) return Tu3(0, 0, 0);

        if(memo[i][j] != notyet) return memo[i][j];
        //can't return here if matrix[i][j] == 0

        //NOTE: must enumerate all even if matrix[i][j] == 0
        int tmp_square = 1 + get<0>( bottom_right(matrix, i-1, j-1) );
        int height = 1 + get<1>( bottom_right(matrix, i-1, j) );
        int width = 1 + get<2>( bottom_right(matrix, i, j-1) );

        if(matrix[i][j] == '0') return memo[i][j] = Tu3(0, 0, 0);
        
        int square = min({tmp_square, height, width});
        max_square = max(max_square, square);

        return memo[i][j] = Tu3(square, height, width);
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();
        memo.resize(m, vector<Tu3>(n, notyet));

        bottom_right(matrix, m-1, n-1);
        return max_square * max_square;
    }
};
