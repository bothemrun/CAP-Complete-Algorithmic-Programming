class Solution {
private:
    int binary_transit(const vector<int>& nums, int low, int high){
        int mid = low + (high-low)/2;
        if(mid+1 > nums.size()-1)return nums[0];
        if(nums[mid] > nums[mid+1])return nums[mid+1];//applies for low==high
        if(low == high)return nums[0];
        
        if(nums[0] < nums[mid])return binary_transit(nums, mid+1, high);
        else return binary_transit(nums, low, mid);
    }
public:
    int findMin(vector<int>& nums) {
        return binary_transit(nums, 0, nums.size()-1);
    }
};
