class Solution {
private:
    int binary_search(const vector<int>& nums, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target)return mid;//applies for size 1
        if(low == high){
            if(target < nums[low])return low;
            else return low+1;
        }
        
        if(nums[mid] < target)return binary_search(nums, target, mid+1, high);
        else return binary_search(nums, target, low, mid);
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }
};
