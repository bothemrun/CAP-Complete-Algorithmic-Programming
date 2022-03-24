#include<string.h>
class Solution {
private:
    void queen(int col_used_by_row[], bool diag1[], bool diag2[], int& ans, int row_used, const int& n){
        if(row_used == n){
            ans++;
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
            }//else: used,skip
        }
    }
public:
    int totalNQueens(int n) {
        int col_used_by_row[n+1]; //1-based 0:not used
        bool diag1[2*n-1 + 2*n];
        bool diag2[2*n-1 + 2*n];
        memset(col_used_by_row,0,sizeof(col_used_by_row));
        memset(diag1,0,sizeof(diag1));
        memset(diag2,0,sizeof(diag2));
        
        int ans = 0;
        queen(col_used_by_row,diag1,diag2, ans, 0, n);
        return ans;
    }
};
