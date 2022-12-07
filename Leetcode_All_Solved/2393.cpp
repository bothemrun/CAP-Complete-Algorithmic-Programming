class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 1;
        int increasing_low = 0;
        for(int i=1;i<n;i++){
            if(!( nums[i-1] < nums[i] ) )
                increasing_low = i;
            
            cnt += i - (increasing_low-1);
        }
        return cnt;
    }
};
