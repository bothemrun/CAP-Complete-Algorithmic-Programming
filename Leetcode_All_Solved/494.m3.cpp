//m3
//use sum(abs(elements)) to bound memo[][sum] instead of memo[][40003]
//space optim bottom up dp.
#define IDX(i) (((i)%2 + 2)%2)
#define Memo(i) (memo[ IDX(i) ])
#define Memo2(i, x) ( (0<=x && x<memo_size)? Memo(i)[x]:0 )
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum_abs = 0;
        for(const int& num: nums) sum_abs += num;
        const int offset = sum_abs + 2;
        const int memo_size = 2*offset + 2;

        vector<vector<int>> memo(2, vector<int>(memo_size, 0));
        //NOTE: trap: +/- nums[0] the same.
        Memo(0)[offset + nums[0]]++;
        Memo(0)[offset - nums[0]]++;

        for(int i=1;i<n;i++)
            for(int s=-sum_abs;s<=sum_abs;s++)
                Memo(i)[offset + s] = Memo2(i-1, offset + s - nums[i]) + Memo2(i-1, offset + s + nums[i]);
        
        //NOTE: edge case
        //return Memo(n-1)[offset + target];
        return Memo2(n-1, offset + target);
    }
};
