//m0
//O(n^2)

#define max_n 100
#define mod ((int)1e9 + 7)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        int memo[max_n][max_n];
        int path[max_n][max_n];

        const int null = INT_MIN;
        memo[n-1][n-1] = 0;
        path[n-1][n-1] = 1;

        for(int i=n-1-1;i>=0;i--){
            if(board[i][n-1] != 'X' && memo[i+1][n-1] != null){
                memo[i][n-1] = ( memo[i+1][n-1] + (board[i][n-1] - '0') )%mod;
                path[i][n-1] = 1;
            }else{
                memo[i][n-1] = null;
                path[i][n-1] = null;
            }

            if(board[n-1][i] != 'X' && memo[n-1][i+1] != null){
                memo[n-1][i] = ( memo[n-1][i+1] + (board[n-1][i] - '0') )%mod;
                path[n-1][i] = 1;
            }else{
                memo[n-1][i] = null;
                path[n-1][i] = null;
            }
        }

        for(int i=n-1-1;i>=0;i--){
            for(int j=n-1-1;j>=0;j--){
                if(board[i][j] != 'X'){
                    //might be 'E'
                    int score1 = (board[i][j]=='E')? 0:(board[i][j] - '0');

                    int max_score = max({
                        memo[i+1][j],
                        memo[i][j+1],
                        memo[i+1][j+1]
                    });

                    memo[i][j] = (max_score==null)? null:( score1 + max_score )%mod;

                    int path_cnt = 0;
                    function<void(int, int)> check = [&path_cnt, &memo, &path, max_score](int x, int y){
                        if(max_score == memo[x][y]){
                            path_cnt = ( path_cnt + path[x][y] )%mod;
                        }
                    };
                    if(memo[i][j] == null){
                        path_cnt = null;
                    }else{
                        check(i+1, j);
                        check(i, j+1);
                        check(i+1, j+1);
                    }
                    path[i][j] = path_cnt;
                }else{
                    memo[i][j] = null;
                    path[i][j] = null;
                }
            }
        }

        if(memo[0][0] == null) return vector<int>({0, 0});
        return vector<int>({memo[0][0], path[0][0]});
    }
};
