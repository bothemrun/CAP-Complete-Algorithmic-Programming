//m0
//recursion with memo.

#define notyet INT_MIN
#include<limits.h>
#include<algorithm>

class Solution {
public:
    //diff of player1 score & player2
    vector<vector<vector<int>>> memo;

    int squeeze(const vector<int>& nums, const int& i, const int& j, bool turn){
        if(i==j) return (turn==false)? nums[i]:( -nums[i] );

        if(memo[i][j][turn] != notyet) return memo[i][j][turn];

        int ret = notyet;
        if(turn == false){
            ret = max(
                //when flipping ~turn, it extends 1 bit into 32 bit int.
                //squeeze(nums, i+1, j, ~turn) + nums[i],
                squeeze(nums, i+1, j, !turn) + nums[i],
                squeeze(nums, i, j-1, !turn) + nums[j]
            );
        }else{
            ret = min(
                squeeze(nums, i+1, j, !turn) - nums[i],
                squeeze(nums, i, j-1, !turn) - nums[j]
            );
        }

        return memo[i][j][turn] = ret;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();

        memo.resize(n, vector<vector<int>>(n, vector<int>(2, notyet) ) );

        return squeeze(nums, 0, n-1, false) >= 0;
    }
};
