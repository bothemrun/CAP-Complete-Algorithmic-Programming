//m0
//recursion with memo. longest increasing subsequence, not so clear to see.
#define notyet (-1)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int rowsize, colsize;
    vector<int> memo;
    int lis(const vector<string>& strs, const int& col){
        if(col < 0) return 0;

        if(memo[col] != notyet) return memo[col];

        int max_lis = 1;
        for(int pre_col=0;pre_col<col;pre_col++){
            //check if 2 columns ascending
            bool ascend = true;
            for(int row=0;row<rowsize;row++)
                if( strs[row][pre_col] > strs[row][col] ){
                    ascend = false;
                    break;
                }
            if(ascend == false) continue;

            max_lis = max(
                max_lis,
                lis(strs, pre_col) + 1
            );
        }

        return memo[col] = max_lis;
    }

    int minDeletionSize(vector<string>& strs) {
        rowsize = strs.size();
        colsize = strs.front().size();

        memo.resize(colsize, notyet);

        int max_lis = 0;
        for(int col=0;col<colsize;col++)
            max_lis = max(
                max_lis,
                lis(strs, col)
            );
        return colsize - max_lis;
    }
};
