//m1
//top down dp
#define notyet (-1)
#include<assert.h>
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int n;
    inline void clear_memo(){
        memo = vector<vector<int>>(n, vector<int>(2, notyet));
    }
    int robber(const vector<int>& nums, const int& low, const int& i, const int& rob_this){
        if(i < low) return 0;
        if(memo[i][rob_this] != notyet)return memo[i][rob_this];

        if(rob_this)
            return memo[i][1] = robber(nums, low, i-1, 0) + nums[i];
        else
            return memo[i][0] = max(
                robber(nums, low, i-1, 0),
                robber(nums, low, i-1, 1)
            );
    }
    inline int house_robber(const vector<int>& nums, const int& low, const int& high){
        //NOTE: crucial
        clear_memo();

        assert(low <= high);
        return max(
            robber(nums, low, high, 0),
            robber(nums, low, high, 1)
        );
    }
    int rob(vector<int>& nums) {
        n = nums.size();

        //edge case: n == 1
        if(!(1 <= n-1))return nums[0];

        return max(
            house_robber(nums, 0, n-1 - 1),
            house_robber(nums, 1, n-1)
        );
    }
};
