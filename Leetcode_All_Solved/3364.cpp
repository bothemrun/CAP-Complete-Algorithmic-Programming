class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int left=0;left<n;left++){
            for(int len=l;len<=r;len++){
                int right = left + (len-1);
                if(right >= n){
                    break;
                }
                
                int sum = 0;
                for(int i=left;i<=right;i++){
                    sum += nums[i];
                }
                if(sum > 0){
                    ans = min(ans, sum);
                }
            }
        }
        return (ans==INT_MAX)? (-1):ans;
    }
};
