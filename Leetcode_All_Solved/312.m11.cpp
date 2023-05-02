//m11
//use int array to init: more significant.
//use macro to replace padd function.

//recursion with memo, padding, last popped
//why last popped? hard to handle rearrangement after popped if we use the first popped viewpoint.
#define max_n 300
#define pad(i) ( (0<=(i) && (i)<n)? nums[i]:1 )
#define notyet (-1)
#include<algorithm>
#include<string.h>
class Solution {
public:
    int n;
    //vector<vector<int>> memo;
    int memo[max_n+1][max_n+1];
    
    int last_pop(const vector<int>& nums, const int& i, const int& j){
        if(!(i <= j)) return 0;//NOTE

        if(memo[i][j] != notyet) return memo[i][j];

        int m = 0;
        for(int k=i;k<=j;k++){
            m = max(m,
                pad(i-1) * nums[k] * pad(j+1) +
                last_pop(nums, i, k-1) +
                last_pop(nums, k+1, j)
            );
        }
        return memo[i][j] = m;
    }
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        //memo.resize(n, vector<int>(n, notyet));
        memset(memo, notyet, sizeof(memo));

        return last_pop(nums, 0, n-1);
    }
};
