//m01
//O(1) space bottom up
#define IDX(i) ((i)%2) //wrong: (i%2)
#include<algorithm>
#include<limits.h>
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> memo(2, vector<int>(3));
        memo[IDX(0)] = costs[0];
        for(int i=1;i<n;i++)
            for(int state=0;state<3;state++){
                memo[IDX(i)][state] = INT_MAX;
                for(int j=0;j<3;j++)if(j != state)
                    memo[IDX(i)][state] = min(
                        memo[IDX(i)][state],
                        costs[i][state] + memo[IDX(i-1)][j]
                    );
            }
        return *min_element(memo[IDX(n-1)].begin(), memo[IDX(n-1)].end() );
    }
};
