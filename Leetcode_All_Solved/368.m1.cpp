//m1
//bottom up dp
#define no_pre (-2)
#include<algorithm>
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, 1);
        vector<int> pre(n, no_pre);

        sort(nums.begin(), nums.end());

        int max_div = 0, max_div_idx = no_pre;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)if(nums[i] % nums[j] == 0){
                if(memo[i] < 1 + memo[j] ){
                    memo[i] = 1 + memo[j];
                    pre[i] = j;
                }
            }

            if(max_div < memo[i]){
                max_div = memo[i];
                max_div_idx = i;
            }
        }


        vector<int> ans;
        int cur = max_div_idx;
        while(cur != no_pre){
            ans.push_back(nums[cur]);
            cur = pre[cur];
        }
        return ans;
    }
};
