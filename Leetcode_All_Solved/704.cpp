class Solution {
private:
    int binary_search(const vector<int>& nums, const int& target, int low, int high){
        if(low == high) return (nums[low]==target)? low:(-1);
        
        int middle = low + (high-low)/2;
        int left = binary_search(nums, target, low, middle);
        int right = binary_search(nums, target, middle+1, high);
        if(left != (-1))return left;
        if(right != (-1))return right;
        return (-1);
    }
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }
};
