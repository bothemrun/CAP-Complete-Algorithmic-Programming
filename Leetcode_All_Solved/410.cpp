//m0
//recursion with memo
#define sum(i, j) ( (i==0)? prefix[j]:(prefix[j] - prefix[i-1]) )
#define notyet (-1)
#define none INT_MAX
#include<limits.h>
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> memo;
    int enum_last_part(const int& i, const int& part){
        if(part == 1) return memo[i][part] = sum(0, i);
        assert(part >= 2 && i>=0);

        if(memo[i][part] != notyet) return memo[i][part];

        int minmax_sum = none;
        for(int j=(part-1) - 1;j<i;j++)
            minmax_sum = min(
                minmax_sum,
                max(
                    sum(j+1, i),
                    enum_last_part(j, part-1)
                )
            );
        return memo[i][part] = minmax_sum;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        prefix.resize(n);
        prefix.front() = nums.front();
        for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + nums[i];

        //1-indexed for partition count
        memo.resize(n, vector<int>(k+1, notyet) );
        return enum_last_part(n-1, k);
    }
};
