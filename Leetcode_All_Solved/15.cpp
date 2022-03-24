#include<algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //trivial
        if(nums.size() <= 2){
            vector<vector<int>> ans;
            return ans;
        }
        
        //sort
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            //similar to Two Sum, Leetcode 1, But (1) find all (2) avoid repetition
            int target = 0 - nums[i];
            int low = i + 1, high = nums.size()-1;
            while(low < high){
                if(nums.at(low) + nums.at(high) == target){
                    vector<int> ans1 {nums[i], nums[low], nums[high]};
                    ans.push_back(ans1);
                    
                    //NOTE: avoid repetition
                    while(low < high && nums.at(low) == nums.at(low+1)) low++;
                    while(low < high && nums.at(high) == nums.at(high-1)) high--;
                    //NOTE: either low++/high-- will conclude to low++ & high-- simultaenously
                    low++; high--;
                }else if(nums[low] + nums[high] < target) low++;
                else high--; //recursive assumption
            }
            
            //NOTE: avoid repetition
            while(i < nums.size()-2 && nums.at(i) == nums.at(i+1)) i++;
        }
        
        return ans;
    }
};
