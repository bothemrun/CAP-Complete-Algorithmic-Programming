//m0
//recursion with memo
#define notyet INT_MIN
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<vector<int>> memo;
    int lis(const int& low, const int& high){
        if(low >= high) return 0;

        if(memo[low][high] != notyet) return memo[low][high];

        int ret = INT_MAX;
        for(int guess=low;guess<=high;guess++)
            ret = min(
                ret,
                guess + max(
                    lis(low, guess-1),
                    lis(guess+1, high)
                )
            );
        return memo[low][high] = ret;
    }
    int getMoneyAmount(int n) {
        memo.resize(n+1, vector<int>(n+1, notyet));

        return lis(1, n);
    }
};
