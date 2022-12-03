//m1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int fuel = 0;
        for(int i=0;i<nums.size()-1;i++){
            fuel = max(fuel, nums[i]);
            if(fuel == 0)return false;
            
            fuel--; //update
        }
        return true;
    }
};
