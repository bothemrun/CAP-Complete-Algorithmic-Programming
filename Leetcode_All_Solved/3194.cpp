class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        double ans = nums.back() + 2.0;
        for(int i=0;i<(n-1)-i;i++){
            ans = min(
                ans,
                ( (double)nums[i] + (double)nums[(n-1)-i] ) / 2.0
            );
        }
        return ans;
    }
};
