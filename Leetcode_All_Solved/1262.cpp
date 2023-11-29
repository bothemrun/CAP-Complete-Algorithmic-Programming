//m0
#define notyet (-1)
#define impossible (-2)
#define divisor 3
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
    vector<vector<int>> memo;
    int enum_mod(const vector<int>& nums, const int& i, const int& remainder){
        if(i==(-1)){
            return (remainder==0)? 0:impossible;
        }

        if(memo[i][remainder] != notyet)
            return memo[i][remainder];

        int r = nums[i]%divisor;

        int ret = enum_mod(nums, i-1, remainder);
        
        int choose = enum_mod(nums, i-1, (remainder-r + divisor)%divisor );
        if(choose != impossible)
            ret = max(ret, choose + nums[i] );
        return memo[i][remainder] = ret;
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<int>(divisor, notyet));
        int ret = enum_mod(nums, n-1, 0);
        return (ret==impossible)? 0:ret;
    }
};
