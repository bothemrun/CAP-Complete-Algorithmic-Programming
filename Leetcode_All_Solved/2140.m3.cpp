//m3
//bottom up dp, optim by reducing from [n][2] to [n] memo states
#define Memo(i) ( (i<n)? memo[i]:0 )
#define max_n ((int)1e5)
#include<algorithm>
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long memo[max_n];
        for(int i=n-1;i>=0;i--)
            memo[i] = max(
                Memo(i+1),
                Memo(i + questions[i][1] + 1) +
                questions[i][0]
            );
        return memo[0];
    }
};
