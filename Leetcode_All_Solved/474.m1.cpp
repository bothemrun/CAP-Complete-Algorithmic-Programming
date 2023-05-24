//m1
//space optim bottom up dp.  knapsack dp.
#define IDX(i) (((i)%2 + 2)%2)
#define Memo(i) (memo[ IDX(i) ])
#define Memo2(i, x, y) ( (0<=x && 0<=y)? Memo(i)[x][y]:none )

#define max_strs 600
#define none INT_MIN

#include<limits.h>
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        int cnt0[max_strs] = {0};
        int cnt1[max_strs] = {0};
        for(int i=0;i<l;i++)
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j] == '0') cnt0[i]++;
                else if(strs[i][j] == '1') cnt1[i]++;
                else assert(false);
            }
        
        vector<vector<vector<int>>> memo( 2, vector<vector<int>>( m+1, vector<int>(n+1, none) ) );
        assert(IDX(-1) < memo.size());
        Memo(-1)[0][0] = 0;//NOTE

        int max_subset = 0;
        for(int i=0;i<l;i++)
            for(int zero=0;zero<=m;zero++)
                for(int one=0;one<=n;one++){
                    int skip = Memo(i-1)[zero][one];
                    int choose = Memo2(i-1, zero - cnt0[i], one - cnt1[i] );

                    Memo(i)[zero][one] = max(
                        skip,
                        ( (choose==none)? none:(choose + 1) )
                    );

                    if(i == l-1) max_subset = max(
                        max_subset,
                        Memo(l-1)[zero][one]
                    );
                }
        
        assert(max_subset != none);
        return max_subset;
    }
};
