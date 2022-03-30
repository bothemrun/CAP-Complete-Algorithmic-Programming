class Solution {
private:
    int binary_transit(const vector<int>& nums, int low, int high){
        int mid = low + (high-low)/2;
        if(mid+1 > nums.size()-1)return 0;//NOTE: handle mid+1 > nums.size()-1
        if(nums[mid] > nums[mid+1])return mid+1;
        if(low == high)return 0;
        
        if(nums[0] < nums[mid])return binary_transit(nums, mid+1, high);
        else return binary_transit(nums, low, mid);
    }
    int binary(const vector<int>& nums, const int& target, int low, int high, const int& offset){
        int mid = low + (high-low)/2;
        if(nums[(mid+offset)%nums.size()] == target)return (mid+offset)%nums.size();//applies for size 1
        if(low == high)return (-1);
        
        if(nums[(mid+offset)%nums.size()] > target)return binary(nums, target, low, mid, offset);
        else return binary(nums, target, mid+1, high, offset);
    }
public:
    int search(vector<int>& nums, int target) {        
        int offset = binary_transit(nums, 0, nums.size()-1);
        return binary(nums, target, 0, nums.size()-1, offset);
    }
};
