//partition O(n^2) * gcd O(log(max_num))

#define none INT_MAX
#define notyet (-1)
#include<algorithm>
#include<numeric> //C++17 gcd()
#include<limits.h>
#include<assert.h>

class Solution {
public:
    vector<vector<int>> al;
    vector<int> memo;

    int enum_partition(const int& i){
        if(i==(-1)) return 0;

        if(al[i].size() == 0) return none;

        if(memo[i] != notyet) return memo[i];

        int cnt = none;
        for(const int& j: al[i]){
            int part = enum_partition(j-1);
            if(part == none) continue;

            cnt = min(cnt, 1 + part);
        }
        return memo[i] = cnt;
    }

    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        al.resize(n);
        //NOTE: pre-compute
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)if(gcd(nums[i], nums[j]) > 1)
                al[i].push_back(j);
            //ok for self, not ok for 1 itself
        
        memo.resize(n, notyet);
        int ret = enum_partition(n-1);
        return (ret==none)? (-1):ret;
    }
};
