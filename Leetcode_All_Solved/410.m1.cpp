//m1
//bottom up dp. like longest increasing subsequence.
#define none INT_MAX
#define sum(i, j) ( (i==0)? prefix[j]:( prefix[j] - prefix[i-1] ) )
#include<limits.h>
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
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix.front() = nums.front();
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];

        //1-indexed for partition count
        vector<vector<int>> memo(n, vector<int>(k+1, none) );
        for(int i=0;i<n;i++){
            memo[i][1] = sum(0, i);

            for(int part=2;part<=k;part++){
                int minmax_sum = none;
                for(int j=(part-1) - 1;j<i;j++){
                    minmax_sum = min(
                        minmax_sum,
                        max(
                            sum(j+1, i),
                            memo[j][part-1]
                        )
                    );
                }
                memo[i][part] = minmax_sum;
            }
        }

        return memo[n-1][k];
    }
};
