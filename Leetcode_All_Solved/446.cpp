//m0
//for a specific arithmetic length = 3.
//O(n^2) dp

#include<unordered_map>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        //index --> diff -->
        //count of arithmetic sequences of length >= 2,
        //while starting from index.
        vector< unordered_map<long long, int> > idx2diff2ari2(n);

        for(int i=n-1;i>=0;i--)
            for(int j=i+1;j<n;j++){
                long long diff = (long long)nums[j] - (long long)nums[i];

                idx2diff2ari2[i][diff] += 1 + idx2diff2ari2[j][diff];
            }

        
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                long long diff = (long long)nums[j] - (long long)nums[i];

                ans += idx2diff2ari2[j][diff];
            }
        
        return ans;
    }
};
