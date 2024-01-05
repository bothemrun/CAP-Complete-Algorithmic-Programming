#include<assert.h>
#include<algorithm>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> window_cnt;

        int max_len = 0;
        //window in [i, j]
        int j=0;
        window_cnt[ nums.front() ] = 1;

        for(int i=0;i<n;i++){
            while(j+1<n && window_cnt[ nums[j+1] ] + 1 <= k ){
                j++;

                window_cnt[ nums[j] ]++;
            }

            max_len = max(max_len, j - (i-1) );

            assert( --window_cnt[ nums[i] ] >= 0 );
        }

        return max_len;
    }
};
