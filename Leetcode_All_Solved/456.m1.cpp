//m1
//O(nlogn) binary search with tree map/set + prefix min.
//much more intuitive than monotonic stack O(n) method.

//1. why can't we use suffix min, and maintain the sorted tree map/set forward?

//1.1. 'cuz different 2's results in different 1's.

//1.2. for backward maintaining the sorted tree map/set, 
//we can ensure there's only one 1's, which is the prefix min.

//2. for nums[k] (2), find the "smallest" > nums[i] (1)
//2.1. so it the smallest not < nums[j] (3), then all others can't.

#include<algorithm>
#include<limits.h>
#include<set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix_min(n, INT_MAX);
        for(int i=1;i<n;i++)
            prefix_min[i] = min(prefix_min[i-1], nums[i-1]);
        

        set<int> suffix_treeset;
        suffix_treeset.insert(nums.back());
        for(int j=n-2;j>=0;j--){
            const int& nums_i = prefix_min[j];
            const int& nums_j = nums[j];

            if(!( nums_i < nums_j )) continue;

            //NOTE: find the "smallest" > nums_i
            //NOTE: so it the smallest not < nums_j (3), then all others can't.
            auto it = suffix_treeset.upper_bound( nums_i );

            if(it != suffix_treeset.end() && nums_j > *it) return true;


            suffix_treeset.insert(nums[j]);
        }

        return false;
    }
};
