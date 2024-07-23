//m0

//[A] 3 pass: prefix & suffix LIS
//[B] LIS by dp in O(n^2)

//O(n^2)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    const int notyet = (-1);

    int enum_ending(vector<int>& memo, const vector<int>& nums, int i){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        int ret = 1;
        for(int j=0;j<i;j++){
            ret = max({
                ret,
                1,
                (nums[j]<nums[i])? (1 + enum_ending(memo, nums, j)):0
            });
        }
        return memo[i] = ret;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        this->n = nums.size();
        
        vector<int> pre_lis(n, notyet);
        for(int i=0;i<n;i++) enum_ending(pre_lis, nums, i);

        reverse(nums.begin(), nums.end());
        vector<int> suf_lis(n, notyet);
        for(int i=0;i<n;i++) enum_ending(suf_lis, nums, i);


        int max_mountain = 3;//testcases guaranteed that there exists 1 mountain.
        for(int i=1;i<n-1;i++)if(pre_lis[i]>=2 && suf_lis[ (n-1) - i ]>=2){
            max_mountain = max(
                max_mountain,
                pre_lis[i] + suf_lis[ (n-1) - i ] - 1
            );
        }
        return n - max_mountain;
    }
};
