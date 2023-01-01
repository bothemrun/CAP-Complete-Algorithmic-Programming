#include<limits.h>
class Solution {
public:
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<vector<bool>> dp_can;
    vector<vector<bool>> in_stack;

    
    int dfs(const vector<vector<int>>& heights, const int& i, const int& j, const int& last_height=INT_MAX){
        //ret: 0:none, 1:pacific, 2:atlantic, 3:both
        if(!(0<=i && i<m && 0<=j && j<n))return 0;

        if(in_stack[i][j] == true)return 0;

        if(heights[i][j] > last_height)return 0;

        if(dp_can[i][j] == true)return 3;
        

        int can = 0;
        if(i == 0 || j == 0) can |= 1;
        if(i == m-1 || j == n-1) can |= 2;

        in_stack[i][j] = true;
        for(int k=0;k<dx.size();k++){
            can |= dfs(heights, i+dx[k], j+ dy[k], heights[i][j] );
        }
        in_stack[i][j] = false;

        if(can == 3) dp_can[i][j] = true;
        return can;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights.back().size();
        dp_can = vector<vector<bool>>(m, vector<bool>(n, false));
        in_stack = vector<vector<bool>>(m, vector<bool>(n, false));
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(dp_can[i][j] == false)
                    dfs(heights, i, j);

                if(dp_can[i][j] == true)
                    ans.push_back( {i, j} );
                
            }
        return ans;
    }
};
