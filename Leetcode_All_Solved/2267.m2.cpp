//m2

//since the count of left parentheses is bounded by (m+n)/2,
//we replace hash set with a bool vector.

//O(mn * max_left) = O(mn * ((m+n)/2)) = 1e6

#define max_n 100
#define max_left (max_n + 1)
#define Memo(i, j, left) ( (i>=0 && j>=0)? memo[i][j][left]:false )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        bool memo[max_n][max_n][max_left+1];

        //edge case
        if(grid[0][0] == ')') return false;

        for(int left=0;left<=max_left;left++) memo[0][0][left] = false;
        memo[0][0][1] = true;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                for(int left=0;left<=max_left;left++){
                    if(grid[i][j]=='('){
                        if(left-1<0){
                            memo[i][j][left] = false;
                        }else{
                            memo[i][j][left] = Memo(i-1, j, left-1) || Memo(i, j-1, left-1);
                        }
                    }else{
                        if(left+1 > max_left){
                            memo[i][j][left] = false;
                        }else{
                            memo[i][j][left] = Memo(i-1, j, left+1) || Memo(i, j-1, left+1);
                        }
                    }
                }
            }
        }

        return memo[m-1][n-1][0];
    }
};
