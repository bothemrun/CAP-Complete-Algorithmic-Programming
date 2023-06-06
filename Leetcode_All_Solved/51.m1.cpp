//m1
//more elegant way
#define max_n (9+1)

class Solution {
public:
    int n;
    int diag2offset;

    //all 1-indexed
    //NOTE: 0 means not used
    bool col_used[max_n] = {0};
    bool diag1[2*max_n] = {0};
    bool diag2[2*max_n] = {0};

    vector<vector<string>> ans;
    vector<string> ans1;
    string raw_row;

    void backtrack(const int& row){
        if(row == n+1){
            ans.push_back(ans1);
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
            string r = raw_row;
            r[col - 1] = 'Q';//to 0-indexed
            ans1.push_back(r);

            backtrack(row+1);

            col_used[col] = false;
            diag1[row+col] = false;
            diag2[row-col + diag2offset] = false;
            ans1.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        diag2offset = n;
        
        raw_row.resize(n, '.');

        backtrack(1);
        return ans;
    }
};
