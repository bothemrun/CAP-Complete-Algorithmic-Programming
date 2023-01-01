//m1
class Solution {
public:
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<vector<int>> can;
    //NOTE: 0:none, 1:pacific, 2:atlantic, 3:both
    vector<vector<bool>> in_stack;

    void dfs(const vector<vector<int>>& heights, const int& i, const int& j, const int& ocean, const int& last_height=(-1)){
        if(!(0<=i && i<m && 0<=j && j<n))return;

        if(in_stack[i][j] == true)return;

        if(!( heights[i][j] >= last_height) )return;

        //NOTE: prune, or TLE !!!
        if(can[i][j] & ocean)return;

        can[i][j] |= ocean;
        in_stack[i][j] = true;
        for(int k=0;k<dx.size();k++)
            dfs(heights, i + dx[k], j + dy[k], ocean, heights[i][j] );
        in_stack[i][j] = false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights.back().size();

        can = vector<vector<int>>(m, vector<int>(n, 0));
        in_stack = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i=0;i<m;i++){
            dfs(heights, i, 0, 1);
            dfs(heights, i, n-1, 2);
        }
        for(int j=0;j<n;j++){
            dfs(heights, 0, j, 1);
            dfs(heights, m-1, j, 2);
        }


        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(can[i][j] == 3)
                ans.push_back( {i, j} );
        return ans;
    }
};


