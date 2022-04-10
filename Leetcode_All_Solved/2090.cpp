class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0)return nums;
        vector<int> ave(nums.size(), (-1));
        
        unsigned long long win_sum = 0;
        for(int i=0;i<2*k+1 && i<nums.size();i++)win_sum += nums[i];
        if(2*k+1 <= nums.size()) ave[k] = win_sum / (2*k+1);
        
        for(int i=k+1;i+k<nums.size();i++) ave[i] = (win_sum = win_sum + nums[i+k] - nums[i-k-1]) / (2*k+1);
        return ave;
    }
};
