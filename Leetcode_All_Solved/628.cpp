//O(n) without O(nlogn) sorting
#define tii tuple<int, vector<int>::iterator >

#include<limits.h>
#include<algorithm>
#include<assert.h>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum POP_TYPE{
    POP_MAX,
    POP_MIN
};

class Solution {
public:
    inline tii pop(vector<int>& nums, int pop_type){
        //auto it;
        auto it = nums.begin();
        int mod_val;

        if(pop_type == POP_MAX){
            it = max_element(nums.begin(), nums.end());
            mod_val = INT_MIN;
        }else if(pop_type == POP_MIN){
            it = min_element(nums.begin(), nums.end());
            mod_val = INT_MAX;
        }else assert(false);

        int val = *it;
        *it = mod_val;

        return {val, it};
    }

    inline void restore(const int& val, auto it){
        *it = val;
    }

    int maximumProduct(vector<int>& nums) {
        auto [val0, it0] = pop(nums, POP_MAX);
        auto [val1, it1] = pop(nums, POP_MAX);
        auto [val2, it2] = pop(nums, POP_MAX);

        restore(val0, it0);
        restore(val1, it1);
        restore(val2, it2);

        auto [min0, mi0] = pop(nums, POP_MIN);
        auto [min1, mi1] = pop(nums, POP_MIN);

        return max(val0 * val1 * val2, val0 * min0 * min1);
    }
};
