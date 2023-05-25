//m1
//bottom up dp.  longest increasing subsequence, not so clear to see.
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
    int minDeletionSize(vector<string>& strs) {
        int rowsize = strs.size();
        int colsize = strs.front().size();

        vector<int> memo(colsize);

        int max_lis = 0;
        for(int col=0;col<colsize;col++){

            int this_lis = 1;
            for(int pre_col=0;pre_col<col;pre_col++){
                //check if 2 columns ascending
                bool ascend = true;
                for(int row=0;row<rowsize;row++)
                    if( strs[row][pre_col] > strs[row][col] ){
                        ascend = false;
                        break;
                    }
                
                if(!ascend) continue;

                this_lis = max(
                    this_lis,
                    1 + memo[pre_col]
                );
            }

            memo[col] = this_lis;
            max_lis = max(max_lis, this_lis);
        }

        return colsize - max_lis;
    }
};
