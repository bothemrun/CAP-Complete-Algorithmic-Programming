//m0

//[A] prefix sum to check valid stamp's top left corner

//1. stamped on the top left corner


//[B] prefix sum again to check if covered by stamps.

//1. check leftwards & upwards rectangle to see if there's any stamps or not


//[C] good implementation to have a prefix sum class

//O(mn)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Range_Sum{
public:
    int m, n;
    vector<vector<long long>> presum;

    inline long long co(int i, int j){
        if(i>=0 && j>=0) return presum[i][j];
        return 0;
    }
    Range_Sum(const vector<vector<int>>& mat){
        this->m = mat.size();
        this->n = mat.back().size();
        presum.resize(m, vector<long long>(n));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                presum[i][j] = (
                    mat[i][j]
                    + co(i, j-1)
                    + co(i-1, j)
                    - co(i-1, j-1)
                );
    }

    long long query(int i, int j, int x, int y){
        return (
            presum[x][y]
            - co(x, j-1)
            - co(i-1, y)
            + co(i-1, j-1)
        );
    }
};

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid.back().size();

        class Range_Sum* ban = new Range_Sum(grid);

        //stamped on top left corner
        vector<vector<int>> stamped(m, vector<int>(n, 0));
        for(int i=0;i + (stampHeight-1)<m;i++)
            for(int j=0;j + (stampWidth-1)<n;j++)if(grid[i][j] == 0){
                if(ban->query(
                    i, j,
                    i + (stampHeight-1),
                    j + (stampWidth-1)
                ) == 0){
                    stamped[i][j] = 1;
                }
            }
        
        //check if can be covered by any stamps
        class Range_Sum* cover = new Range_Sum(stamped);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 0){
                if(cover->query(
                    max(i - (stampHeight-1), 0),
                    max(j - (stampWidth-1), 0),
                    i,
                    j
                ) == 0){
                    return false;
                }
            }
        
        return true;
    }
};
