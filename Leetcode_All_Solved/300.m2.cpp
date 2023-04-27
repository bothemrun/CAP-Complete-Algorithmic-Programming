//m2
//recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<int> memo;
    int lis(const vector<int>& nums, const int& i){
        if(memo[i] != notyet)return memo[i];

        memo[i] = 1;
        for(int j=0;j<i;j++)if(nums[j] < nums[i])
            memo[i] = max(memo[i], 1 + lis(nums, j) );
        return memo[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, notyet);
        
        //NOTE: wrong: lis(nums, n-1);
        for(int i=0;i<n;i++)
            lis(nums, i);
        return *max_element(memo.begin(), memo.end());
    }
};
