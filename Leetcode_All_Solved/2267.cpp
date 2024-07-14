//m0

//O(mn * operation for 1 cell) = O(mn * ((m+n)/2)) = 1e6

#define max_n 100
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

        //count of left parentheses
        unordered_set<int> memo[max_n][max_n];

        //edge case
        if(grid[0][0] == ')') return false;

        memo[0][0].insert(1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int delta = (grid[i][j]=='(')? 1:(-1);

                if(i-1>=0){
                    for(const int& left: memo[i-1][j]){
                        if(left + delta >= 0){
                            memo[i][j].insert(left + delta);
                        }
                    }
                }

                if(j-1>=0){
                    for(const int& left: memo[i][j-1]){
                        if(left + delta >= 0){
                            memo[i][j].insert(left + delta);
                        }
                    }
                }
            }//for j
        }

        return memo[m-1][n-1].count(0) != 0;
    }
};
