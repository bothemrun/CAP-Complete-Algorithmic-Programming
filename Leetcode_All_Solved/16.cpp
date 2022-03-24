#include<algorithm>
#include<stdlib.h>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sort
        sort(nums.begin(), nums.end());
        
        int closest_sum = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.size()-2;i++){
            //Two Sum, Leetcode 1
            int low = i + 1, high = nums.size()-1;
            while(low < high){
                if(abs(nums[low] + nums[high] + nums[i] - target) < abs(closest_sum - target) )
                    closest_sum = nums[low] + nums[high] + nums[i];
                
                if(nums[low] + nums[high] + nums[i] == target) return target;
                else if(nums[low] + nums[high] + nums[i] < target) low++;
                else high--; 
                //NOTE: Recursive Assumption : elements outside [low,high] all are farther away from target.
            }
        }
        return closest_sum;
    }
};
