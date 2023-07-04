//m0

//1. got inspiration from votrubac solution:
//NOTE: the concept of the minimum window [i2, j] & the maximum window [i1, j] of right end j.

//the maximum window is formed by 
//(a) starting with the minimum window. 
//(b) extending the left end by adding elements that the minimum window already has.


//2. read editorial solution.
//NOTE: maintain 2 sliding window for the max & min window [i1, j] & [i2, j]
//NOTE: and i1 & i2 are monotonically increasing.

//votrubac's implementation is too hard to understand.
//editorial's method of the same concept is more understandable.

#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cnt_distinct_window{
public:
    vector<int> cnt;
    int distinct = 0;

    cnt_distinct_window(int size){
        cnt.resize(size, 0);
    }

    void add(const int& x){
        cnt[x]++;
        if(cnt[x] == 1) distinct++;
    }
    void remove(const int& x){
        assert(cnt[x] >= 1);
        cnt[x]--;
        if(cnt[x] == 0) distinct--;
    }
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        //NOTE: 2 counting windows for the max & min window.
        //[0 ~ n]
        class cnt_distinct_window max_win = cnt_distinct_window(n + 1);
        int max_win_left = 0;

        class cnt_distinct_window min_win = cnt_distinct_window(n + 1);
        int min_win_left = 0;
        //NOTE: [max_win_left, min_win_left) are good.

        int subarray = 0;
        for(int right=0;right<n;right++){
            max_win.add( nums[right] );
            min_win.add( nums[right] );

            //if distinct > k, shrink to [max_win_left, min_win_left) have distinct == k
            while(max_win_left <= right && max_win.distinct > k){
                max_win.remove( nums[max_win_left] );
                max_win_left++;
            }

            while(min_win_left <= right && min_win.distinct >= k){
                min_win.remove( nums[min_win_left] );
                min_win_left++;
            }

            if( max_win.distinct == k )
                subarray += (min_win_left-1) - (max_win_left-1);
        }

        return subarray;
    }
};
