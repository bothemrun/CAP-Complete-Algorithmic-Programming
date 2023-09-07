#include<algorithm>

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mi = *min_element(nums.begin(), nums.end());
        int ma = *max_element(nums.begin(), nums.end());
        for(const int& x: nums)if(x != mi && x != ma) return x;
        return (-1);
    }
};
