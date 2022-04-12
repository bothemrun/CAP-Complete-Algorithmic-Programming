#include<algorithm>
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unsigned long long win_product = 1;
        int pre_good_high = 0-1;
        for(int low=0;low<n;low++){
            int high;//NOTE
            for(high=max(low-1, pre_good_high);high+1<n;high++){
                if(win_product * nums.at(high+1) < k)
                    win_product *= nums.at(high+1);
                else break;
            }
            
            pre_good_high = high;
            ans += high - (low-1);
            if(high >= low)
                win_product /= nums.at(low);
        }
        return ans;
    }
};
