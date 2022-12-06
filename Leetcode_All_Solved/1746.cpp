#include<algorithm>
struct performed{
    int notyet;
    int already;
};
bool cmp_fn(const struct performed& p1, const struct performed& p2){
    return p1.already < p2.already;
}
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        vector<struct performed> dp_ending(n);
        struct performed p0 = {nums[0], nums[0]*nums[0]};
        dp_ending[0] = p0;
        
        for(int i=1;i<n;i++){
            int notyet = max(nums[i], dp_ending[i-1].notyet + nums[i]);
            int already = max(nums[i]*nums[i], max( nums[i]*nums[i] + dp_ending[i-1].notyet, nums[i] + dp_ending[i-1].already ) );
            struct performed pi = {notyet, already};
            dp_ending[i] = pi;
        }
        return max_element(dp_ending.begin(), dp_ending.end(), cmp_fn)->already;
    }
};

