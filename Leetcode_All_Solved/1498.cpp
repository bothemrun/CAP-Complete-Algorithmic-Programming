#define mod ((int)1e9 + 7)
#include<algorithm>
class Solution {
public:
    long long mod_exp(const long long& a, const long long& b, const long long& m){
        if(b == 0) return 1;

        long long res = mod_exp(a, b/2, m);
        res = (res * res)%m;
        return ( (b%2 == 1)? a*res:res )%m;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cnt = 0;
        for(int low=0;low<n;low++){
            //NOTE: [low, high]
            int high = ( upper_bound(nums.begin(), nums.end(), target - nums[low] ) - nums.begin() ) - 1;
            if(!(low <= high)) break;

            //NOTE: 2^( high - low ), then for low == high, 2^0 = 1, since we need non-empty subsequences
            cout << (high-low)<<endl;
            //NOTE: WA for 1LL << 63LL: cnt = ( cnt + ( 1LL << (long long)(high-low) )%(long long)mod )%mod;
            cnt = ( cnt + mod_exp(2, high-low, mod) )%mod;
        }
        return cnt;
    }
};
