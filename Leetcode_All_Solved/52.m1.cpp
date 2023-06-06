//m1
//more elegant way

#define max_n (9+1)
class Solution {
public:
    int n;
    int diag2offset;
    //all 1-indexed
    bool col_used[max_n] = {0};
    bool diag1[2*max_n] = {0};
    bool diag2[2*max_n] = {0};
    int cnt = 0;

    void backtrack(const int& row){
        if(row == n+1){
            cnt++;
            return;
        }

        for(int col=1;col<=n;col++){
            if(
                col_used[col] ||
                diag1[row+col] ||
                diag2[row-col + diag2offset]
            ) continue;

            col_used[col] = true;
            diag1[row+col] = true;
            diag2[row-col + diag2offset] = true;

            backtrack(row+1);

            col_used[col] = false;
            diag1[row+col] = false;
            diag2[row-col + diag2offset] = false;
        }
    }

    int totalNQueens(int n) {
        this->n = n;
        diag2offset = n;

        backtrack(1);
        return cnt;
    }
};
