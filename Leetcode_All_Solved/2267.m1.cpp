//m1

//dp memory optim

//O(mn * operation for 1 cell) = O(mn * ((m+n)/2)) = 1e6

#define Memo_assign(i, j) ( memo[ ( (i)%2 + 2 )%2 ][j] )
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
        unordered_set<int> memo[2][max_n];

        //edge case
        if(grid[0][0] == ')') return false;

        Memo_assign(0, 0).insert(1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                
                Memo_assign(i, j).clear();

                int delta = (grid[i][j]=='(')? 1:(-1);

                if(i-1>=0){
                    for(const int& left: Memo_assign(i-1, j) ){
                        if(left + delta >= 0){
                            Memo_assign(i, j).insert(left + delta);
                        }
                    }
                }

                if(j-1>=0){
                    for(const int& left: Memo_assign(i, j-1) ){
                        if(left + delta >= 0){
                            Memo_assign(i, j).insert(left + delta);
                        }
                    }
                }
            }//for j
        }

        return Memo_assign(m-1, n-1).count(0) != 0;
    }
};
