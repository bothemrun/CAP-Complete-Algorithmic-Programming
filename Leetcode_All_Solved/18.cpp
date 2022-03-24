#include<algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //trivial
        if(nums.size() <= 3){
            vector<vector<int>> ans;
            return ans;
        }
        
        //sort
        sort(nums.begin(), nums.end());
        //
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++){
            //like 3Sum, Leetcode 15.
            //(1) find all combi (2) avoid repetition
            for(int j=i+1;j<nums.size()-2;j++){
                //Two Sum
                int targ = target - nums[i] - nums[j];
                int low = j + 1, high = nums.size()-1;
                while(low < high){
                    if((long long)nums[i]+(long long)nums[j]+(long long)nums[low]+(long long)nums[high] == (long long)target){
                        vector<int> ans1 {nums[i],nums[j],nums[low],nums[high]};
                        ans.push_back(ans1);
                        
                        //NOTE: avoid repetition
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        //NOTE: either low++/high-- leads to simultaneously:
                        low++; high--;
                    }else if((long long)nums[i]+(long long)nums[j]+(long long)nums[low]+(long long)nums[high] > (long long)target) high--;
                    else low++; //recursive assumption
                }
                
                //NOTE: avoid repetition
                while(j < nums.size()-2 && nums[j] == nums[j+1]) j++;
            }
            //NOTE: avoid repetition
            while(i < nums.size()-3 && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};
