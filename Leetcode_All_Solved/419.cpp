class Solution {
private:
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(!(0<=i && i <m && 0<=j && j<n))return;
        if(board[i][j] == '.')return;
        board[i][j] = '.';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(board[i][j] == 'X'){
            dfs(board, i, j);
            ans++;
        }
        return ans;
    }
};
