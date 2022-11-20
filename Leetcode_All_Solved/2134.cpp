#include<algorithm>
class Solution {
public:
    int n;
    inline int circular(int i){
        return (i+n)%n;
    }
    int minSwaps(vector<int>& nums) {
        n = nums.size();
        
        int window_size = 0;//count 1's
        for(int& num:nums)if(num == 1)
            window_size++;
        
        int window0 = 0;
        for(int i=0;i<window_size;i++)if(nums[ circular(0 - i) ] == 0)
            window0++;
        
        int min_swap = window_size;
        for(int i=0;i<nums.size();i++){
            min_swap = min(min_swap, window0);
            
            //update
            int i_del = circular(i - (window_size-1));
            int i_add = circular(i + 1);
            if(nums[i_del] == 0)
                window0--;
            if(nums[i_add] == 0)
                window0++;
        }
        return min_swap;
    }
};
