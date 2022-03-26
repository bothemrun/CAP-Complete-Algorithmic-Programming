//m1
class Solution {
private:
    int binary_search_check_mid(const vector<int>& nums, const int& target, int low, int high){
        int middle = low + (high-low)/2;
        if(nums[middle] == target)return middle;//also applies for size 1 interval
        if(low == high)return (-1);
        
        if(target <= nums[middle]) return binary_search_check_mid(nums, target, low, middle);
        else return binary_search_check_mid(nums, target, middle+1, high);
    }
public:
    int search(vector<int>& nums, int target) {
        return binary_search_check_mid(nums, target, 0, nums.size()-1);
    }
};
