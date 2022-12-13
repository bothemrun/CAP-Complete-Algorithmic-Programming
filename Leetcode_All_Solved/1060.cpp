#include<limits.h>
#include<assert.h>
class Solution {
public:
    int n;
    inline int missing_cnt(const vector<int>& nums, const int& i){
        if(i >= n)return INT_MAX;

        int total_cnt = nums[i] - (nums[0]-1);
        int present_cnt = i - (0-1);
        return total_cnt - present_cnt;
    }
    int binary_interval(const vector<int>& nums, const int& target_cnt, int low, int high){
        int mid = low + (high-low)/2;
        int missing_cnt2 = missing_cnt(nums, mid+1);
        int missing_cnt1 = missing_cnt(nums, mid);

        if(missing_cnt2 == INT_MAX)
            return n-1;
        
        if(missing_cnt1 < target_cnt &&
            target_cnt <= missing_cnt2)
            return mid;
        
        //NOTE: included low == high
        assert(low != high);

        if(target_cnt <= missing_cnt1)
            return binary_interval(nums, target_cnt, low, mid);
        else return binary_interval(nums, target_cnt, mid+1, high);
    }
    int missingElement(vector<int>& nums, int k) {
        n = nums.size();
        int interval_i = binary_interval(nums, k, 0, n-1);
        //NOTE: k 1-indexed, so not +1
        return nums[interval_i] + (k - missing_cnt(nums, interval_i) );
    }
};
