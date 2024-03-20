//m0
//wisdompeak's Interval I: Partition

//with a special status value.
//O(nk*2) = O(nk)

//optim: cache locality:
//1. dp[n][k][2] --> 2000ms
//2. dp[n][2][k] --> 500ms

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
    long long k;
    vector<vector<vector<long long>>> memo;
    const long long notyet = LLONG_MIN;
    const long long impossible = LLONG_MIN + 1;

    //NOTE: const int& --> TLE
    //the probable reason is dp memo is large O(1e6), 
    //so for calls to the un-modified func(part),
    //we need to look up deeply to the recursion stack
    
    //long long enum_last_partition_cover(const vector<int>& nums, const int& i, const int& part, bool must_cover){
    long long enum_last_partition_cover(const vector<int>& nums, int i, int part, bool must_cover){

        //pruning
        if(i < part) return impossible;

        if(part==(-1)) return 0;


        assert(i>=0 && part>=0);
        if(memo[i][must_cover][part] != notyet) return memo[i][must_cover][part];

        long long mult = k - part;
        if(part%2 == 1) mult *= (-1);

        //1. if must_cover==true: from (i-1, part-1, false) & (i-1, part, true)
        long long ret = max(
            enum_last_partition_cover(nums, i-1, part-1, false),
            enum_last_partition_cover(nums, i-1, part, true)
        );
        if(ret != impossible){
            ret += mult * (long long)nums[i];
        }

        //2. if must_cover==false: also from (i-1, part, false)
        if(must_cover == false){
            ret = max(
                ret,
                enum_last_partition_cover(nums, i-1, part, false)
            );
        }

        return memo[i][must_cover][part] = ret;
    }

    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        this->k = k;

        //optim: cache locality
        memo.resize(n, vector<vector<long long>>(2, vector<long long>(k, notyet) ) );
        return enum_last_partition_cover(nums, n-1, k-1, false);
    }
};
