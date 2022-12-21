class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        int cnt = 0;
        vector<vector<int>> row1pair(n, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            vector<int> row1idx;
            for(int j=0;j<n;j++)if(grid[i][j] == 1)
                row1idx.push_back(j);
            
            for(int a=1;a<row1idx.size();a++){
                for(int b=0;b<a;b++){
                    cnt += row1pair[ row1idx[b] ][ row1idx[a] ];
                    //update, won't interfere
                    row1pair[ row1idx[b] ][ row1idx[a] ]++;
                }
            }
        }
        return cnt;
    }
};
