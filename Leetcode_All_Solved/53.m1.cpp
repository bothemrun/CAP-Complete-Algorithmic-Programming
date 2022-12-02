//m1
//divide and conquer
#include<algorithm>
#include<limits.h>
class Solution {
public:
    int divide_conquer(const vector<int>& nums, int low, int high){
        if(low == high)return nums[low];
        
        int mid = low + (high-low)/2;//NOTE: no overflow. 
        //NOTE: no low > high if (low, mid) and (mid+1, high), and with mid+1 <= right boundary
        int l_max = divide_conquer(nums, low, mid);
        int r_max = divide_conquer(nums, mid+1, high);
        
        //NOTE: conquer in O(n)
        int r_cross_max = INT_MIN;
        int right_sum = 0;
        //for(int i=mid+1;i<nums.size();i++){
        for(int i=mid+1;i<=high;i++){
            right_sum += nums[i];
            r_cross_max = max(r_cross_max, right_sum);
        }
        
        int l_cross_max = INT_MIN;
        int left_sum = 0;
        //for(int i=mid;i>=0;i--){
        for(int i=mid;i>=low;i--){
            left_sum += nums[i];
            l_cross_max = max(l_cross_max, left_sum);
        }
        
        //NOTE: merge
        return max( l_cross_max + r_cross_max, max(l_max, r_max) );
    }
    int maxSubArray(vector<int>& nums) {
        return divide_conquer(nums, 0, nums.size() - 1);
    }
};
