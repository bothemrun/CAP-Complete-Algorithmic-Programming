class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int i_valid = 0;
        for(;i<nums.size();i++){
            if(nums.at(i) == val)
                continue;
            nums.at(i_valid) = nums.at(i);
            i_valid++;
        }
        return i_valid;
    }
};
