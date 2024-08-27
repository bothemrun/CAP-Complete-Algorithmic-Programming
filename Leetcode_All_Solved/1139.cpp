//O(n^2 + n^3)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<vector<int>> left1(m, vector<int>(n));
        vector<vector<int>> top1(m, vector<int>(n));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    left1[i][j] = 0;
                    top1[i][j] = 0;
                }else{
                    left1[i][j] = 1 + ((j-1>=0)? left1[i][j-1]:0);
                    top1[i][j] = 1 + ((i-1>=0)? top1[i-1][j]:0);
                }
            }
        
        int max_side = 0;
        //(i, j) bottom right corner
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                for(int d=0; i-d>=0 && j-d>=0 ;d++){
                    //top left corner
                    int x = i-d, y = j-d;
                    //bottom left = (i, y)
                    //top right = (x, j)

                    if(
                        left1[i][j] >= d+1 &&
                        top1[i][j] >= d+1 &&
                        top1[i][y] >= d+1 &&
                        left1[x][j] >= d+1
                    ) max_side = max(max_side, d+1);
                }
        return max_side*max_side;
    }
};
