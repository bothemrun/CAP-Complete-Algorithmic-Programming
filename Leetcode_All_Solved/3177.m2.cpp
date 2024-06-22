//m2

//O(k*n)

//1. use a jump table to jump back to last index of the same value.

//2. dp_end[i][diff] := end at i (must choose [i]), at most "diff" different pairs avaible (not exactly)

//2.a. dp_choose_or_skip[i][diff] --> no. if the last recursion uses same pair (no diff-1), then can't skip it !!!

//3. so still need dp prefix max --> as get<1>(tii)

#define tii tuple<int, int>
#include<tuple>
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int no_jump = (-1);
    vector<int> jump;

    const tii notyet = tii(-1, -1);
    vector<vector<tii>> memo;

    tii enum_end_jump(const vector<int>& nums, int i, int diff){
        if(i<0) return tii(0, 0);
        if(diff<0) return tii(0, 0);

        if(memo[i][diff] != notyet) return memo[i][diff];

        int dp_end = max({
            1, //self
            1 + get<0>( enum_end_jump(nums, jump[i], diff) ), //same pair
            1 + get<1>( enum_end_jump(nums, i-1, diff-1) ) //possibly different or same pair
        });

        int prefix_max = max({
            dp_end, //self & same pair
            get<1>( enum_end_jump(nums, i-1, diff) ) //just prefix max by previous dp
        });

        return memo[i][diff] = {dp_end, prefix_max};
    }

    int maximumLength(vector<int>& nums, int k) {
        unordered_map<int, int> val2last_idx;
        int n = nums.size();
        jump.resize(n);
        for(int i=0;i<n;i++){
            const int val = nums[i];

            jump[i] = 
                (val2last_idx.count(val)==0)?
                no_jump:
                val2last_idx[val];
            
            //update
            val2last_idx[val] = i;
        }


        memo.resize(n, vector<tii>(k+1, notyet));
        return get<1>( enum_end_jump(nums, n-1, k) );
    }
};
