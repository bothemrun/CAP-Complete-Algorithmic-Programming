//m1
//recursion with memo, padding, last popped
//why last popped? hard to handle rearrangement after popped if we use the first popped viewpoint.
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    int n;
    vector<vector<int>> memo;
    inline int pad(const vector<int>& nums, const int& i){
        if(0<=i && i<n) return nums[i];
        else return 1;
    }
    int last_pop(const vector<int>& nums, const int& i, const int& j){
        if(!(i <= j)) return 0;//NOTE

        if(memo[i][j] != notyet) return memo[i][j];

        for(int k=i;k<=j;k++){
            memo[i][j] = max(memo[i][j],
                pad(nums, i-1) * nums[k] * pad(nums, j+1) +
                last_pop(nums, i, k-1) +
                last_pop(nums, k+1, j)
            );
        }
        return memo[i][j];
    }
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        memo.resize(n, vector<int>(n, notyet));

        return last_pop(nums, 0, n-1);
    }
};
