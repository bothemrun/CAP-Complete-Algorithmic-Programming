#include<algorithm>
class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int max_first = nums.front();
        int max_first_idx = 0;
        for(int i=0;i+k-1 < n;i++)if(nums[i] > max_first){
            max_first = nums[i];
            max_first_idx = i;
        }

        vector<int> ans(k);
        for(int i=0;i<k;i++)
            ans[i] = nums[i+max_first_idx];
        return ans;
    }
};
