//m0
//O(n^2) dp Basic II
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
    vector<int> memo;//no overflow

    int enum_prefix(const vector<int>& nums, int i){
        if(!(i<n)) return 0;

        if(memo[i] != notyet) return memo[i];

        int ret = 0;
        for(int j=i+1;j<n;j++){
            ret = max(
                ret,
                (j-i) * nums[j] + enum_prefix(nums, j)
            );
        }
        return memo[i] = ret;
    }

    int maxScore(vector<int>& nums) {
        this->n = nums.size();
        memo.resize(n, notyet);

        return enum_prefix(nums, 0);
    }
};
