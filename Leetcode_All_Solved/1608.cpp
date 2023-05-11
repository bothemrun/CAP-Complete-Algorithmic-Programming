#include<algorithm>
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int x=0;x<=n;x++){
            //[low, n-1]
            int low = lower_bound(nums.begin(), nums.end(), x ) - nums.begin();
            if(x == (n-1) - (low-1) ) return x;
        }
        return (-1);
    }
};
