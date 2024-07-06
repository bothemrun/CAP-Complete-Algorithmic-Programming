//m0
//O(n) dp
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int notyet = (-1);
    //dp(i, desired mod, last parity)
    vector<vector<vector<int>>> memo;

    int enum_subs(const vector<int>& nums, int i, const bool desired_mod, bool last_par){
        if(i<0) return 0;//any desired_mod / last_par is ok

        if(memo[i][desired_mod][last_par] != notyet)
            return memo[i][desired_mod][last_par];
        
        if(nums[i]%2 == last_par){
            //choose
            return memo[i][desired_mod][last_par] = 1 + enum_subs(nums, i-1, desired_mod, desired_mod ^ last_par);
        }else{
            //skip
            return memo[i][desired_mod][last_par] = enum_subs(nums, i-1, desired_mod, last_par);
        }
    }

    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<vector<int>>(2, vector<int>(2, notyet) ) );

        return max({
            enum_subs(nums, n-1, 0, 0),
            enum_subs(nums, n-1, 0, 1),
            enum_subs(nums, n-1, 1, 0),
            enum_subs(nums, n-1, 1, 1)
        });
    }
};
