#include<algorithm>
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_diff = nums[nums.size()-1] - nums[0];
        for(int i=0;i-1+k<nums.size();i++)
            min_diff = min(min_diff, nums[i-1+k] - nums[i]);
        return min_diff;
    }
};
