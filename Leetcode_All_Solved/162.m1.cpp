//m1
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //NOTE: nums[i] != nums[i + 1] for all valid i
        int low = 0, high = nums.size()-1;
        while(!(low == high)){
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[mid+1])//mid+1 <= high_max since !(low == high)
                low = mid+1;
            else high = mid;
        }
        return low;
    }
};
