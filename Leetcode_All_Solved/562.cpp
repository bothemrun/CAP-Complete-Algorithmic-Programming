#define d(i,j,k) (DP(dp, i, j, k))
#include<algorithm>
class Solution {
public:
    int m, n;
    inline int DP(const vector<vector<vector<int>>>& dp, const int& i, const int& j, const int& k){
        if( !(0<=i && i<m && 0<=j && j<n) )
            return 0;
        return dp[i][j][k];
    }
    
    int longestLine(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat.back().size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, 0)) );
        
        int max_line = 0;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    dp[i][j] = {
                        1 + d(i-1, j-1, 0),
                        1 + d(i-1, j, 1),
                        1 + d(i-1, j+1, 2),
                        1 + d(i, j-1, 3)
                    };
                    max_line = max(max_line, *max_element(dp[i][j].begin(), dp[i][j].end()) );
                }
            }
        
        return max_line;
    }
};



