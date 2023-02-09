#include<algorithm>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i0 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                if(i != i0) swap(nums[i0], nums[i]);

                i0++;
            }
        }
    }
};
