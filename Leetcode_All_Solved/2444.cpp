//m0
//sliding window + two pointer in O(n)

//[A] Dimension Reduction: Fix subarray's left end.

//[B] ignore bad zones


//[C] 1st sliding window for good zone.

//1. [i, good]


//[D] 2nd sliding window & window counts for meeting minK & maxK

//1. [i, min_bound]
//2. edge case: minK == maxK

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum CNT{
    MIN_CNT,
    MAX_CNT
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;

        //1st window for good zone. [i, good]
        int good = (-1);

        //2nd window & window counts for the shortest fixed bound subarray.
        //[i, min_bound]
        int min_bound = (-1);
        vector<int> cnt(2, 0);

        for(int i=0;i<n;i++){
            //1st window
            good = max(good, i-1); //keep

            while(good+1<n && minK <= nums[good+1] && nums[good+1] <= maxK ){
                good++;
            }

            if(!(i <= good)) continue;

            //2nd window
            min_bound = max(min_bound, i-1); //keep

            while(
                min_bound+1<n &&
                min_bound+1<=good &&
                ( cnt[MIN_CNT]==0 || cnt[MAX_CNT]==0 )
            ){
                min_bound++;

                //edge: minK == maxK
                if(nums[min_bound] == minK) cnt[MIN_CNT]++;
                if(nums[min_bound] == maxK) cnt[MAX_CNT]++;
            }

            //answer
            if(cnt[MIN_CNT] != 0 && cnt[MAX_CNT] != 0){
                ans += good - (min_bound-1);
            }

            //update, drop
            //edge: minK == maxK
            if(nums[i] == minK) assert(--cnt[MIN_CNT] >= 0);
            if(nums[i] == maxK) assert(--cnt[MAX_CNT] >= 0);
        }

        return ans;
    }
};
