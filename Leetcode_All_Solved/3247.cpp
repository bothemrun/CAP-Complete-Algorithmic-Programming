//m0
//O(n)
//DP Basic I
#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int mod = (int)1e9 + 7;
    vector<tii> memo;
    const tii notyet = tii(-1, -1);

    tii last_subs(const vector<int>& nums, int i){
        if(i<0) return {0, 0};

        if(memo[i] != notyet) return memo[i];

        auto [last_even, last_odd] = last_subs(nums, i-1);
        int even = 0, odd = 0;
        if(nums[i]%2 == 0){
            even = last_even + 1 + last_even ;
            odd = last_odd + 0 + last_odd;
        }else{
            even = last_even + 0 + last_odd;
            odd = last_odd + 1 + last_even;
        }
        return memo[i] = {even%mod, odd%mod};
    }

    int subsequenceCount(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, notyet);

        return get<1>( last_subs(nums, n-1) );
    }
};
