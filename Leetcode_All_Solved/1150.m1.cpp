//m1
#include<assert.h>
class Solution {
public:
    int n;

    inline bool good(const vector<int>& nums, const int& target, const int& i){
        if( !(0<=i && i<n) )return false;

        //NOTE:
        if(nums[i] <= target)return true;
        return false;
    }

    int upperbound(const vector<int>& nums, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(good(nums, target, mid) &&
            good(nums, target, mid + 1) == false)
            return mid;
        //NOTE: includes low == high
        if(low == high){
            //not found
            if(low == 0)return (-1);
            else if(low == n)return n;
            assert(false);
        }

        if(nums[mid] <= target)
            return upperbound(nums, target, mid+1, high);
        else return upperbound(nums, target, low, mid);
    }

    bool isMajorityElement(vector<int>& nums, int target) {
        n = nums.size();
        int high = upperbound(nums, target, 0, n-1);
        int low = upperbound(nums, target - 1, 0, n-1) + 1;
        
        if(high == INT_MIN) return false;
        if( high - (low-1) > n/2 )return true;
        else return false;
    }
};
