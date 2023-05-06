//m2
//pre-compute modular exponentiation, instead of divide & conquer modular expontiation.
//NOTE: use compare & subtract instead of modulo:
// if(x >= mod) x -= mod
// works because 2 * ( mod = 1e9 + 7 ) < INT_MAX


//m1: improved from n binary searches to two pointers 
#define mod ((int)1e9 + 7)
#define max_len ((int)1e5)
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
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //NOTE: fast mod exponentiation
        int pow2mod[max_len + 1] = {1};
        for(int i=1;i<=n;i++){
            pow2mod[i] = pow2mod[i-1] << 1;

            if(pow2mod[i] >= mod) pow2mod[i] -= mod;//NOTE: fast mod
        }

        int cnt = 0;
        //optim
        int high = ( upper_bound(nums.begin(), nums.end(), target - nums[0] ) - nums.begin() ) - 1;
        //[low, high]
        for(int low=0;low<n;low++){
            while(low <= high && !(nums[low] + nums[high] <= target) ) high--;
            if(!(low <= high)) break;

            cnt += pow2mod[high-low];

            if(cnt >= mod) cnt -= mod;//NOTE: fast mod
        }

        return cnt;
    }
};
