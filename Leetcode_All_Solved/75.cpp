#include<algorithm>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //NOTE: no 0 between [i0, i-1]
        int i0 = 0;
        for(int i=0;i<n;i++)if(nums[i] == 0)
            swap(nums[i], nums[i0++]);
        
        //NOTE: no 2 between [i+1, i2]
        int i2 = n-1;
        for(int i=n-1;i>=i0;i--)if(nums[i] == 2)
            swap(nums[i], nums[i2--]);
    }
};
