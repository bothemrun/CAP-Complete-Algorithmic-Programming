//O(n) by modifying min/max for 2nd min/max, w/o sorting.
#include<algorithm>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        auto mi1_it = min_element(nums.begin(), nums.end());
        int mi1 = *mi1_it;
        *mi1_it = INT_MAX;

        auto mi2_it = min_element(nums.begin(), nums.end());
        int mi2 = *mi2_it;


        //NOTE: so 1st/2nd min won't have the same indices as 1st/2nd max.
        *mi2_it = INT_MIN;
        *mi1_it = INT_MIN;


        auto ma1_it = max_element(nums.begin(), nums.end());
        int ma1 = *ma1_it;
        *ma1_it = INT_MIN;

        int ma2 = *max_element(nums.begin(), nums.end());

        return ma2*ma1 - mi1*mi2;
    }
};
