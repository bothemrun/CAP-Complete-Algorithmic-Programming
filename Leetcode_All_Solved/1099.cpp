#include<limits.h>
#include<algorithm>
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.size()-1;
        int max_sum = INT_MIN;
        while(low < high){
            //NOTE: while(low < high && nums[low] + nums[high] < k) low++;
            while(low + 1 < high && nums[low + 1] + nums[high] < k) low++;
            
            //NOTE: might not satisfy
            if(nums[low] + nums[high] < k) max_sum = max(max_sum, nums[low] + nums[high]);
            
            high--;
        }
        return (max_sum == INT_MIN)? (-1):max_sum;
    }
};
