//m01
//O(1) space, bottom up
#define notyet (-1)
#define IDX(i) ((i)%2) // wrong: (i%2)
#include<algorithm>
#include<assert.h>
class Solution {
public:
    vector<vector<int>> memo;
    inline void clear_memo(){
        memo = vector<vector<int>>(2, vector<int>(2));
    }
    inline int house_robber(const vector<int>& nums, const int& low, const int& high){
        assert(low <= high);
        clear_memo();
        memo[IDX(low)] = {0, nums[low]};
        for(int i=low+1;i<=high;i++){
            memo[IDX(i)][1] = nums[i] + memo[IDX(i-1)][0];
            memo[IDX(i)][0] = max(
                memo[IDX(i-1)][0],
                memo[IDX(i-1)][1]
            );
        }
        return max(memo[IDX(high)][0], memo[IDX(high)][1] );
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        //edge case: n==1
        if(!(1<=n-1)) return nums[0];

        return max(
            house_robber(nums, 0, n-1 - 1),
            house_robber(nums, 1, n-1)
        );
    }
};
