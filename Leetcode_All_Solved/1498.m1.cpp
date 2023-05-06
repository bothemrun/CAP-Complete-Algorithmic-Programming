//m1
//improved from n binary searches to two pointers
#define mod ((long long)1e9 + 7)
#include<algorithm>
class Solution {
public:
    long long mod_exp(const long long& a, const long long& b, const long long& m){
        if(b == 0) return 1;

        long long res = mod_exp(a, b/2, m);
        res = (res*res)%m;
        return ( (b%2==1)? a*res:res )%m;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long cnt = 0;
        //optim
        int high = ( upper_bound(nums.begin(), nums.end(), target - nums[0] ) - nums.begin() ) - 1;
        //NOTE: [low, high], [low] must exist since non-empty
        for(int low=0;low<n;low++){
            while(low <= high && !(nums[low] + nums[high] <= target) ) high--;
            if(!(low <= high)) break;

            cnt = ( cnt + mod_exp(2, high-low, mod) )%mod;
        }

        return (int)cnt;
    }
};
