//O(n^3)
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++){
                int res = 0;
                for(int k=i;k<=j;k++){
                    res |= nums[k];
                }
                
                if(res >= k){
                    ans = min(ans, j - (i-1) );
                }
            }
        if(ans == INT_MAX) return (-1);
        return ans;
    }
};
