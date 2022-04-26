#include<algorithm>
class Solution {
private:
    int n;
    int binary_bound(const vector<int>& nums, const int& target, int low, int high){
        if(low > high)return (-1);
        int mid = low + (high-low)/2;
        if(mid+1 < n && nums[mid] < target && target <= nums[mid+1])return mid;
        if(mid == n-1 && nums[mid] < target)return n-1;
        if(low == high)return (-1);
        
        if(nums[mid] >= target)return binary_bound(nums, target, low, mid);
        else return binary_bound(nums, target, mid+1, high);
    }
public:
    int triangleNumber(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int nonzero_i = 0;
        while(nonzero_i < n && nums[nonzero_i] == 0)nonzero_i++;
        for(int i=nonzero_i;i<n;i++)for(int j=i+1;j<n;j++){
            //NOTE: i < j < bound quarantees that the other 2 triangle inequalities hold.
            // find min bound s.t. nums[i]+nums[j]>nums[bound]
            int max_high = binary_bound(nums, nums[i]+nums[j], j+1, n-1);
            if(max_high != (-1))ans += max_high - j;
        }
        return ans;
    }
};
