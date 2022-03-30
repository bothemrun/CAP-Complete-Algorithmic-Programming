#include<algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <= 2)return ans;
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int target = 0 - nums[i];
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(nums[j]+nums[k] == target){
                    ans.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    
                    //NOTE: can't de-duplicate after having considered the case
                    while(j < k && nums[j] == nums[j+1])j++;
                    while(j < k && nums[k] == nums[k-1])k--;
                    
                    j++; k--;//NOTE: will conclude to this simultaenously
                    
                    //NOTE: de-duplicate
                    /*while(j < k && nums[j] == nums[j+1])j++;
                    while(j < k && nums[k] == nums[k-1])k--;*/
                }else if(nums[j]+nums[k] < target)j++;
                else k--;//NOTE: not need to go backwards [j+1, k2], k2 > k. why? : where was [j0,k2] at before? (1)j0<=j, ok, already covered. (2)j0==j+1, impossible, since (a)never go backwards before (b)only 1 option for each state.
                
                //NOTE: de-duplicate
                //NOTE: can't here. not having considered [...,1,1,1,....], but then !(j < k) after j++
                /*while(j < k && nums[j] == nums[j+1])j++;
                while(j < k && nums[k] == nums[k-1])k--;*/
                //NOTE:
                /*while((j+1) < k && nums[j] == nums[j+1])j++;
                while(j < (k-1) && nums[k] == nums[k-1])k--;*/
            }
            
            //NOTE: de-duplicate
            while(i < nums.size()-2 && nums[i] == nums[i+1])i++;
        }
        
        return ans;
    }
};
