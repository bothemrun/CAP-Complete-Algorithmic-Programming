#include<algorithm>
class wiggle{
public:
    int up;
    int down;
    wiggle(){
        up = 1;
        down = 1;
    }
    wiggle(int up_, int down_){
        up = up_;
        down = down_;
    }
};
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<class wiggle> dp(n);
        dp[0] = wiggle();
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1];
            if(nums[i-1] < nums[i])
                dp[i].up = max(dp[i-1].up, dp[i-1].down + 1 );
            else if(nums[i-1] > nums[i])
                dp[i].down = max(dp[i-1].down, dp[i-1].up + 1 );
        }
        return max(dp.back().up, dp.back().down);
    }
};



