//m0
//brute force O(n^2 logn)
#define mod ((int)1e9 + 7)
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for(int i=0;i<n;i++){
            int s = 0;
            for(int j=i;j<n;j++){
                s = (s + nums[j])%mod;

                sums.push_back(s);
            }
        }
        sort(sums.begin(), sums.end());

        int ans = 0;
        for(int i=left;i<=right;i++){
            ans = (ans + sums[i-1])%mod;
        }
        return ans;
    }
};
