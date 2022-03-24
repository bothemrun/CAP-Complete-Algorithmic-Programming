#include<string.h>
#define n 9
class Solution {
private:
    void make(const vector<vector<char>>& board, bool row_used[][n+1], bool col_used[][n+1], bool box_used[][n][n+1], vector<vector<int>>& empty_cell){
        for(int r=0;r<n;r++)for(int c=0;c<n;c++){
            if(board[r][c] == '.'){
                vector<int> cell {r, c};
                empty_cell.push_back(cell);
            }else{
                int k = board[r][c] - '0';
                row_used[r][k] = true;
                col_used[c][k] = true;
                box_used[r/3][c/3][k] = true;
            }
        }
    }
    
    bool dfs_backtrack_prune(vector<vector<char>>& board, bool row_used[][n+1], bool col_used[][n+1], bool box_used[][n][n+1], vector<vector<int>>& empty_cell){
        if(empty_cell.size() == 0) return true;
        
        vector<int> cell = empty_cell.back();
        empty_cell.pop_back();
        int r = cell.at(0), c = cell.at(1);
        for(int k=1;k<=n;k++)if(row_used[r][k]==false && col_used[c][k]==false && box_used[r/3][c/3][k]==false){
            row_used[r][k] = true;
            col_used[c][k] = true;
            box_used[r/3][c/3][k] = true;
            char k_char = '0' + k;
            board[r][c] = k_char;
            if(dfs_backtrack_prune(board,row_used,col_used,box_used, empty_cell) == true) return true;//NOTE: prune
            
            row_used[r][k] = false;//NOTE: backtrack
            col_used[c][k] = false;
            box_used[r/3][c/3][k] = false;
            board[r][c] = '.';
        }
        
        empty_cell.push_back(cell); //NOTE: for bad past path. backtrack
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row_used[n][n+1];//[0-based row][1~9]
        bool col_used[n][n+1];
        bool box_used[n][n][n+1];//[0-based row/3][0-based col/3][1~9]
        memset(row_used,0,sizeof(row_used));//NOTE: can't use in function calls
        memset(col_used,0,sizeof(col_used));
        memset(box_used,0,sizeof(box_used));
        
        vector<vector<int>> empty_cell;
        
        make(board,row_used,col_used,box_used, empty_cell);
        
        dfs_backtrack_prune(board,row_used,col_used,box_used, empty_cell);
    }
};
