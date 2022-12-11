#include<assert.h>
#include<limits.h>
class Solution {
public:
    int n;
    inline bool good(const vector<int>& nums, const int& target, const int& i){
        if(i == n || i == (-1))return false;
        return nums[i] == target;
    }

    inline int upperbound(const vector<int>& nums, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        //NOTE: includes low == high
        if(good(nums,target, mid) == true && 
            good(nums, target, mid+1) == false )
            return mid;
        
        if(low == high)return INT_MIN;

        if(nums[mid] <= target)
            return upperbound(nums, target, mid+1, high);
        else return upperbound(nums, target, low, mid);
    }

    int lowerbound(const vector<int>& nums, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        //NOTE: includes low == high
        if(good(nums,target, mid) == true && 
            good(nums,target, mid-1) == false)
            return mid;
        
        if(low == high)return INT_MAX;

        if(target <= nums[mid])
            return lowerbound(nums, target, low, mid);
        else return lowerbound(nums, target, mid+1, high);
    }

    bool isMajorityElement(vector<int>& nums, int target) {
        n = nums.size();
        int upper = upperbound(nums, target, 0, n-1);
        int lower = lowerbound(nums, target, 0, n-1);

        if(upper == INT_MIN)return false;
        if(upper - (lower-1) > n/2)return true;
        else return false;
    }
};
