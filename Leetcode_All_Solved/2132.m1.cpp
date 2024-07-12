//m1

//[A] use range sum(prefix sum) to check if there are any occupied cells or not


//[B] use 2d diff array to mark all stamped cells, not just the top left corner.

#define coor(m, i, j) ( (i>=0 && j>=0)? m[i][j]:0 )

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Range_Sum{
    int m, n;
    vector<vector<long long>> presum;
public:
    Range_Sum(const vector<vector<int>>& mat){
        m = mat.size();
        n = mat.back().size();

        presum.resize(m, vector<long long>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                presum[i][j] = (
                    mat[i][j]
                    + coor(presum, i-1, j)
                    + coor(presum, i, j-1)
                    - coor(presum, i-1, j-1)
                );
    }

    long long query(int i, int j, int x, int y){
        return (
            presum[x][y]
            - coor(presum, x, j-1)
            - coor(presum, i-1, y)
            + coor(presum, i-1, j-1)
        );
    }
};

class Diff_Arr{
    vector<vector<int>> diff;
    int m, n;
public:
    Diff_Arr(int m, int n){
        this->m = m;
        this->n = n;
        //must size+1
        diff.resize(m + 1, vector<int>(n + 1, 0));
    }

    void range_update(int i, int j, int x, int y, int val){
        diff[i][j] += val;

        diff[i][y+1] -= val;
        diff[x+1][j] -= val;

        diff[x+1][y+1] += val;
    }

    void compute_diff(vector<vector<int>>& mat){
        mat.resize(m, vector<int>(n));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = (
                    diff[i][j]
                    + coor(mat, i-1, j)
                    + coor(mat, i, j-1)
                    - coor(mat, i-1, j-1)
                );
    }
};

class Solution {
public:
    

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid.back().size();

        class Range_Sum* ban = new Range_Sum(grid);
        class Diff_Arr* stamped = new Diff_Arr(m, n);

        for(int i=0;i + (stampHeight-1)<m;i++)
            for(int j=0;j + (stampWidth-1)<n;j++)if(grid[i][j] == 0){
                if(ban->query(
                    i, j,
                    i + (stampHeight-1),
                    j + (stampWidth-1)
                ) == 0){
                    stamped->range_update(
                        i, j,
                        i + (stampHeight-1),
                        j + (stampWidth-1),
                        1
                    );
                }
            }
        

        vector<vector<int>> cover;
        stamped->compute_diff(cover);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 0 && cover[i][j] == 0)
                return false;
        return true;
    }
};
