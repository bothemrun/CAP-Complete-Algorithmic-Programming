#include<limits.h>
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int subarray0_low = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] == 0)
                if(subarray0_low != INT_MAX)
                    cnt += i - (subarray0_low-1);
                else{
                    cnt++;
                    subarray0_low = i;
                }
            else{
                subarray0_low = INT_MAX;
            }
        }        
        return cnt;
    }
};
