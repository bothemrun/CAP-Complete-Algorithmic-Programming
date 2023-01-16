class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        if(nums.size() == 1)return true;
        int i = 1;
        while(i<n && nums[i-1] == nums[i]) i++;
        
        //NOTE:
        if(i == n)return true;

        bool increasing = nums[i-1] < nums[i];
        
        for(;i<n;i++){
            if(increasing){
                if(nums[i-1] > nums[i])return false;
            }else{
                if(nums[i-1] < nums[i])return false;
            }
        }
        return true;
    }
};
