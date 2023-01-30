#include<algorithm>
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size()/2;
        sort(nums.begin(), nums.end());

        int sum = 0;
        for(int i=0;i<n;i++)
            sum += nums[i*2];
        return sum;
    }
};
