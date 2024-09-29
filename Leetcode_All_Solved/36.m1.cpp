//m1
//clear logic
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_cnt[9][9+1] = {0};
        bool col_cnt[9][9+1] = {0};
        bool sub_cnt[3][3][9+1] = {0};
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                char b = board[i][j];
                if(b=='.') continue;
                
                int val = b - '0';
                if(row_cnt[i][val]) return false;
                row_cnt[i][val] = true;
                
                if(col_cnt[j][val]) return false;
                col_cnt[j][val] = true;
                
                if(sub_cnt[i/3][j/3][val]) return false;
                sub_cnt[i/3][j/3][val] = true;
            }
        return true;
    }
};
