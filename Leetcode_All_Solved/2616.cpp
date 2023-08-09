//m0
//binary search the answer, with greedy check.

//greedy proof:

//(0) first sort nums.

//(1) pair(i, i+1) is always better than pair(i, i+k), k >= 2,
//since we can always shrink the pair index to make the difference smaller.

//(2) since p <= nums.length/2, we can always fit p pairs with the scheme in (1).

//(3) so we iterate thru nums, if:
//(3.1) if pair(i, i+1) within max diff, then good++ and check pair(i+2, i+3) next.
//(3.2) if pair(i, i+1) not within max diff, then check pair(i+1, i+2) next.

#include<algorithm>
#include<stdlib.h>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int p;
    int n;
    inline bool greedy_check(const vector<int>& nums, const int& max_diff){
        //assert(p > 0);

        int good = 0;
        int i = 0;
        while(i+1<n){
            if(abs( nums[i] - nums[i+1] ) <= max_diff){
                if(++good == p) return true;

                i += 2;
            }else i++;
        }

        return false;
    }

    int binary(const vector<int>& nums, const int& low, const int& high){
        int mid = low + (high-low)/2;
        
        bool mid_res = greedy_check(nums, mid);
        if(mid_res && greedy_check(nums, mid-1)==false)
            return mid;
        
        if(mid_res)
            return binary(nums, low, mid);
        else return binary(nums, mid+1, high);
    }

    int minimizeMax(vector<int>& nums, int p) {
        this->n = nums.size();
        this->p = p;
        if(p==0) return 0;

        sort(nums.begin(), nums.end());
        return binary(nums, 0, nums.back() - nums.front() );
    }
};
