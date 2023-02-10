#include<algorithm>
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int min_e = nums.front(), min_i = 0;
        int max_e = nums.front(), max_i = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < min_e){
                min_e = nums[i];
                min_i = i;
            }

            //NOTE: min for <, max for <=

            if(max_e <= nums[i]){
                max_e = nums[i];
                max_i = i;
            }
        }

        int cnt = min_i + (n-1) - max_i;
        if(min_i > max_i)
            cnt--;
        return cnt;
    }
};
