//m2
//O(1) space bottom up
#define IDX(i) ((i)%2) //wrong: (i%2)
#include<algorithm>
enum{
    state_down,
    state_up
};
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(2, vector<int>(2));
        memo[IDX(0)] = {1, 1};

        for(int i=1;i<n;i++){
            memo[IDX(i)] = memo[IDX(i-1)];

            //NOTE: 2 options even if ascending !!!
            if(nums[i-1] < nums[i])
                memo[IDX(i)][state_up] = max(
                    memo[IDX(i-1)][state_up],
                    1 + memo[IDX(i-1)][state_down]
                );
            else if(nums[i-1] > nums[i])
                memo[IDX(i)][state_down] = max(
                    memo[IDX(i-1)][state_down],
                    1 + memo[IDX(i-1)][state_up]
                );
        }
        return max(memo[IDX(n-1)][state_down], memo[IDX(n-1)][state_up]);
    }
};
