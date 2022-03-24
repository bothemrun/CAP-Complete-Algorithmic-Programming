#include<string.h>
class Solution {
private:
    void make_1_solution(int col_used_by_row[], vector<vector<string>>& ans, const int& n){
        vector<string> ans1;
        for(int row=1;row<=n;row++){
            string ans_row = "";
            for(int col=1;col<=n;col++){
                if(col_used_by_row[col] == row) ans_row += "Q";
                else ans_row += ".";
            }
            ans1.push_back(ans_row);
        }
        ans.push_back(ans1);
    }
    
    void queen(int col_used_by_row[], bool diag1[], bool diag2[], vector<vector<string>>& ans, int row_used, const int& n){
        if(row_used == n){
            make_1_solution(col_used_by_row, ans, n);
            return;
        }
        
        int use_row = row_used + 1;
        for(int col=1;col<=n;col++){
            if(col_used_by_row[col] == 0 && diag1[use_row+col] == false && diag2[use_row-col+n] == false){
                col_used_by_row[col] = use_row;
                diag1[use_row+col] = true;
                diag2[use_row-col+n] = true;
                queen(col_used_by_row,diag1,diag2,ans, row_used + 1, n);
                col_used_by_row[col] = 0;
                diag1[use_row+col] = false;
                diag2[use_row-col+n] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        int col_used_by_row[n+1];//1-based
        bool diag1[2*n-1 + 2*n];
        bool diag2[2*n-1 + 2*n];
        memset(col_used_by_row,0,sizeof(col_used_by_row));
        memset(diag1,0,sizeof(diag1));
        memset(diag2,0,sizeof(diag2));
        
        vector<vector<string>> ans;
        queen(col_used_by_row,diag1,diag2, ans, 0, n);
        return ans;
    }
};
