#include<limits.h>
#include<algorithm>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> prefix_sum(n);
        prefix_sum[0] = gas[0] - cost[0];
        for(int i=1;i<n;i++)
            prefix_sum[i] = prefix_sum[i-1] + gas[i] - cost[i];
        

        vector<int> prefix_min(n);
        prefix_min[0] = prefix_sum[0];
        for(int i=1;i<n;i++)
            prefix_min[i] = min(prefix_min[i-1], prefix_sum[i]);
        
        vector<int> suffix_min(n);
        suffix_min.back() = prefix_sum.back();
        for(int i=n-1-1;i>=0;i--)
            suffix_min[i] = min(suffix_min[i+1], prefix_sum[i]);


        for(int i=0;i<n;i++){
            int left_sum = (i!=0)? prefix_sum[i-1]:0;
            int right_sum = (i!=0)? (prefix_sum.back() - prefix_sum[i-1]):INT_MIN;//don't care if i==0

            int left_min = (i != 0)? (prefix_min[i-1] + right_sum):INT_MAX;
            int right_min = suffix_min[i] - left_sum;

            if(left_min >= 0 && right_min >= 0)return i;
        }

        return (-1);
    }
};
