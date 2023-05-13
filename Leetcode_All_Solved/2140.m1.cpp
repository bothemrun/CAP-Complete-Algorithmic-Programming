//m1
//bottom up dp
#define max_n ((int)1e5)
#define Memo(i, j) ( (i<n)? memo[i][j]:0 )
#include<algorithm>
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long memo[max_n][2] = {0};
        for(int i=n-1;i>=0;i--){
            memo[i][0] = max(
                Memo(i+1, 0),
                Memo(i+1, 1)
            );
            memo[i][1] = questions[i][0] + max(
                Memo(i + questions[i][1] + 1, 0),
                Memo(i + questions[i][1] + 1, 1)
            );
        }
        return max(
            memo[0][0],
            memo[0][1]
        );
    }
};
