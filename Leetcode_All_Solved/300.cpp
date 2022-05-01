//PH
#include<algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //NOTE: end[i] := LIS ending at nums[i]
        //NOTE: end[j] = 1+max{end[i], 0<=i<j, nums[i] < nums[j]}
        int n = nums.size();
        vector<int> end(n, 1);
        for(int j=0;j<n;j++){
            for(int i=0;i<j;i++)if(nums[i] < nums[j])
                end[j] = max(end[j], end[i]+1);
        }
        
        //max of end[j]
        int lis = 1;
        for(int i=0;i<n;i++)
            lis = max(lis, end[i]);
        return lis;
    }
};
