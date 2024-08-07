class neighborSum {
public:
    vector<vector<int>> g;
    int n;
    vector<int> row, col;

    neighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        row.resize(n*n);
        col.resize(n*n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                row[ g[i][j] ] = i;
                col[ g[i][j] ] = j;
            }
    }

    inline int get(int i, int j){
        if(!(0<=i && i<n && 0<=j && j<n)) return 0;
        return g[i][j];
    }

    int adjacentSum(int value) {
        int i = row[value];
        int j = col[value];

        return get(i+1, j) + get(i-1, j) + get(i, j+1) + get(i, j-1);
    }
    
    int diagonalSum(int value) {
        int i = row[value];
        int j = col[value];

        return get(i-1, j-1) + get(i+1, j+1) + get(i+1, j-1) + get(i-1, j+1);
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
