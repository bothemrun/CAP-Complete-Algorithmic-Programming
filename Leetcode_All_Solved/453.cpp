#include<algorithm>
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minall = *min_element(nums.begin(), nums.end());
        int decrement = 0;
        for(const int& num: nums)
            decrement += num - minall;
        return decrement;
    }
};
