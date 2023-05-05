//m0
//recursion with memo
#define no_pre (-2)
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<int> memo;
    vector<int> pre;
    int divisible(const vector<int>& nums, const int& i){
        if(memo[i] != notyet) return memo[i];

        int div = 1;
        for(int j=0;j<i;j++)if(nums[i] % nums[j] == 0){
            if(div < 1 + divisible(nums, j) ){
                div = 1 + divisible(nums, j);
                pre[i] = j;
            }
        }
        return memo[i] = div;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, notyet);
        pre.resize(n, no_pre);

        sort(nums.begin(), nums.end());

        int max_div = 0, max_div_idx = no_pre;
        for(int i=0;i<n;i++){
            if(max_div < divisible(nums, i) ){
                max_div = divisible(nums, i);
                max_div_idx = i;
            }
        }


        vector<int> ans;
        int cur = max_div_idx;
        while(cur != no_pre){
            ans.push_back( nums[cur] );
            cur = pre[cur];
        }
        return ans;
    }
};
