//Thinking Process:

//[A] fix 1 index
//1. but which to fix?

//[B] fix the middle index
//1. then we can decouple the front/prefix & back/suffix parts by enumerating j
//2. the problem becomes: 

//[C] find suffix max
//1. by ordinary preprocessing.
//2. can also use ordered tree's binary search.

//[D] find prefix max, but < nums[j]
//1. by an ordered tree (tree set) & its binary search.

//O(nlogn)

#include<set>
#include<algorithm>
#include<limits.h>
#include<iostream>
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffix_max(n);
        suffix_max.back() = INT_MIN;

        for(int j=n-2;j>=0;j--){
            suffix_max[j] = max(
                suffix_max[j+1],
                nums[j+1]
            );
        }

        int max_val = INT_MIN;

        set<int> prefix_s;
        prefix_s.insert(nums.front());

        for(int j=1;j+1<n;j++){
            auto it = prefix_s.lower_bound(nums[j]);
            if( it != prefix_s.begin() && nums[j] < suffix_max[j] ){
                it--;

                max_val = max(
                    max_val,
                    *it - nums[j] + suffix_max[j]
                );
            }

            //update, no matter what
            prefix_s.insert(nums[j]);
        }

        return max_val;
    }
};
