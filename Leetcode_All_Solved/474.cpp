//m0
//recursion with memo
#define notyet (-1)
#define max_strs 600
#define none INT_MIN
#include<assert.h>
#include<algorithm>
#include<limits.h>
class Solution {
public:
    int cnt0[max_strs] = {0};
    int cnt1[max_strs] = {0};
    vector<vector<vector<int>>> memo;

    int knapsack(const int& i, const int& zero, const int& one){
        if(i == (-1)) return (zero==0 && one==0)? 0:none;
        if(zero<0 || one<0) return none;

        if(memo[i][zero][one] != notyet) return memo[i][zero][one];

        int skip = knapsack(i-1, zero, one);
        int choose = knapsack(i-1, zero - cnt0[i], one - cnt1[i] );

        return memo[i][zero][one] = max(
            skip,
            ( (choose==none)? none:(choose + 1) )
        );
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0;i<strs.size();i++)
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j] == '0') cnt0[i]++;
                else if(strs[i][j] == '1') cnt1[i]++;
                else assert(false);
            }
        
        memo.resize( strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, notyet) ) );
        //NOTE: not [m][n]

        int max_subset = 0;
        for(int zero=0;zero<=m;zero++)
            for(int one=0;one<=n;one++)
                max_subset = max(
                    max_subset,
                    knapsack(strs.size()-1, zero, one)
                );
        
        return max_subset;
    }
};
