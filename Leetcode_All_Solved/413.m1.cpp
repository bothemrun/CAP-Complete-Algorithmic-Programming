//m1
//recursion with memo
//NOTE: don't remember the difference info, since we compare 3 adjacent numbers.
//then when calling previous [i-1], then comparison condition would still hold.
#define notyet (-1)
class Solution {
public:
    vector<int> memo;
    int enum_end_arith3subarray(const vector<int>& nums, const int& i){
        if(!(i-2>=0)) return 0;

        if(memo[i] != notyet) return memo[i];

        if( nums[i] - nums[i-1] == nums[i-1] - nums[i-2] )
            return 1 + enum_end_arith3subarray(nums, i-1);
        else return 0;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, notyet);
        
        int cnt = 0;
        for(int i=0;i<n;i++)
            cnt += enum_end_arith3subarray(nums, i);
        return cnt;
    }
};
