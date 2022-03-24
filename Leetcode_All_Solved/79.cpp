class Solution {
private:
    bool dfs(vector<vector<char>>& board, const string& word, int& cur_checked_char, int i, int j, const int& m, const int& n){
        //if(cur_checked_char == word.size()) return true;
        if(!( 0<=i && i<m && 0<=j && j<n )) return false;//not affect
        
        if(board[i][j] != word.at(cur_checked_char)) return false;
        
        cur_checked_char++;
        if(cur_checked_char == word.size()) return true;
        char board_tmp = board[i][j];
        board[i][j] = '.';//used
        if(dfs(board,word, cur_checked_char, i+1, j, m,n) == true)return true;
        if(dfs(board,word, cur_checked_char, i-1, j, m,n) == true)return true;
        if(dfs(board,word, cur_checked_char, i, j+1, m,n) == true)return true;
        if(dfs(board,word, cur_checked_char, i, j-1, m,n) == true)return true;
        
        cur_checked_char--; //NOTE: backtrack
        board[i][j] = board_tmp;
        return false;//NOTE: bad past path. backtrack
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int cur_checked_char = 0;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(board[i][j] == word[0]){
            if(dfs(board,word,cur_checked_char, i, j, m,n) == true) return true;
        }
        return false;
    }
};
