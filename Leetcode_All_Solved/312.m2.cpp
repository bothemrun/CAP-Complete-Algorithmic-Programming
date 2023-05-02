//m2
//bottom up dp, padding, last popped.
//why last popped? hard to handle rearrangement after popped if we use the first popped viewpoint.
#define max_n 300
#define pad(i) ((0<=i && i<n)? nums[i]:1)
#define memo_pad(i, j) ( (i<=j)? memo[i][j]:0 )
#include<algorithm>
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int memo[max_n][max_n];
        for(int l=1;l<=n;l++){
            for(int i=0;(i+l-1)<n;i++){
                int j = i + (l-1);
                //pop [i, j], last popped is k
                int m = 0;
                for(int k=i;k<=j;k++){
                    m = max(m,
                        pad(i-1) * nums[k] * pad(j+1) +
                        memo_pad(i, k-1) +
                        memo_pad(k+1, j)
                    );
                }
                memo[i][j] = m;
            }
        }

        return memo[0][n-1];
    }
};
