//m0
//bottom up dp.
//longest increasing subsequence, enumerate partition.
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        //dp[i] := answer for arr[0, i]
        vector<int> dp_ending(n, INT_MIN);
        for(int i=0;i<n;i++){
            //make 1 subarray / partition [j, i]

            //max of arr[j, i]
            int window_max = arr[i];
            
            for(int j=i;j>=0 && j>=(i-(k-1) ); j--){
                window_max = max(window_max, arr[j]);

                int last_partition = (j-1>=0)? dp_ending[j-1]:0;
                int window_len = i - (j-1);

                dp_ending[i] = max(
                    dp_ending[i],
                    last_partition + window_len * window_max
                );
            }
        }

        return dp_ending[n-1];
    }
};
