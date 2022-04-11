class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_sum = {nums[0]};
        for(int i=1;i<n;i++)prefix_sum.push_back(prefix_sum.back() + nums[i]);
        
        vector<int> diff;
        for(int i=0;i<n;i++){
            int n_left = i;
            int n_right = n-1-i;
            //NOTE: can decompose abs() |*|
            if(i == 0)diff.push_back( prefix_sum.back() - prefix_sum[0] - n_right*nums[0] );
            else if(i == n-1)diff.push_back( n_left*nums.back() - prefix_sum[n-1-1] );
            else diff.push_back( (prefix_sum.back() - prefix_sum[i] - n_right*nums[i]) + (n_left*nums[i] - prefix_sum[i-1]) );
        }
        return diff;
    }
};
