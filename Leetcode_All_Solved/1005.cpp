#include<algorithm>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i;
        for(i=0;i<min(n, k);i++){
            if(nums[i] >= 0)break;

            nums[i] = -nums[i];
        }
        k -= (i-1) - (0-1);

        if(k > 0 && k%2 == 1){
            if(i == n) nums.back() = -nums.back();
            else if(i == 0) nums.front() = -nums.front();
            else{
                if(nums[i-1] < nums[i])
                    nums[i-1] = -nums[i-1];
                else nums[i] = -nums[i];
            }
        }

        int sum = 0;
        for(int i=0;i<n;i++)sum += nums[i];
        return sum;
    }
};
