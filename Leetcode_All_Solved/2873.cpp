//O(n) with prefix & suffix max
#include<algorithm>

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix_j(n);
        int prefix_max_i = nums.front();
        for(int j=1;j<n;j++){
            prefix_j[j] = prefix_max_i - nums[j];

            //update
            prefix_max_i = max(prefix_max_i, nums[j] );
        }

        vector<long long> suffix_k(n);
        suffix_k.back() = nums.back();
        for(int k=n-2;k>=2;k--){
            suffix_k[k] = max( (long long)nums[k], suffix_k[k+1] );
        }


        long long ans = 0;
        for(int j=1;j<n-1;j++)
            ans = max(ans, prefix_j[j] * suffix_k[j+1] );
        return ans;
    }
};
