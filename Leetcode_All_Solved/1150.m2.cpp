//m2
//binary search by stl
#include<algorithm>

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        //[low, high)
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int high = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        int n = nums.size();
        int len = (high-1) - (low-1);
        return len > n/2;
    }
};
