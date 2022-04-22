class Solution {
private:
    int binary_upwards(const vector<int>& nums, int low, int high){
        if(low == high)return low;
        int mid = low + (high-low)/2;
        if(nums[mid] < nums[mid+1])//mid+1 <= high_max
            return binary_upwards(nums, mid+1, high);
        else return binary_upwards(nums, low, mid);
    }
public:
    int findPeakElement(vector<int>& nums) {
        //NOTE: nums[i] != nums[i+1] for all valid i
        return binary_upwards(nums, 0, nums.size()-1);
    }
};
