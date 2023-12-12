#include<algorithm>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto ma_it = max_element(nums.begin(), nums.end());
        int ma = *ma_it;

        *ma_it = 0;

        return (ma-1) * (
            *max_element(nums.begin(), nums.end()) - 1
        );
    }
};
