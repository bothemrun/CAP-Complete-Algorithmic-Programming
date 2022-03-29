class Solution {
private:
    int m, n;
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, bool capture=false){
        if(!(0<=i && i<m && 0<=j && j<n))return;
        if(board[i][j] != 'O')return;
        if(visited[i][j] == true)return;
        visited[i][j] = true;
        
        if(capture == true) board[i][j] = 'X';
        
        dfs(board,visited,i+1,j,capture);
        dfs(board,visited,i-1,j,capture);
        dfs(board,visited,i,j+1,capture);
        dfs(board,visited,i,j-1,capture);
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O' && visited[i][0]==false)dfs(board, visited, i, 0);
            if(board[i][n-1] == 'O' && visited[i][n-1]==false)dfs(board, visited, i, n-1);
        }
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O' && visited[0][j]==false)dfs(board, visited, 0, j);
            if(board[m-1][j] == 'O' && visited[m-1][j]==false)dfs(board, visited, m-1, j);
        }
        
        //capture
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(board[i][j]=='O' && visited[i][j]==false)
            dfs(board, visited, i, j, true);
    }
};
