//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define add_mod(a, b) ( (a+b)%mod )
#define mul_mod(a, b) ( (a*b)%mod )
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const long long mod = (long long)1e9 + 7;
        int n = nums.size();

        unordered_map<long long, long long> sum, cnt;
        long long ans = 0;
        
        for(const int& x_int: nums){
            const long long x = x_int;
            long long up = mul_mod( x, cnt[x+1] );
            long long down = mul_mod( x, cnt[x-1] );
            
            long long cur = add_mod( up, down );
            cur = add_mod( cur, x );//self size 1
            cur = add_mod( cur, sum[x+1] );
            cur = add_mod( cur, sum[x-1] );
            
            ans = add_mod( ans, cur );
            cnt[x] = add_mod( cnt[x], 1 );//self size 1
            cnt[x] = add_mod( cnt[x], add_mod( cnt[x+1], cnt[x-1] ) );
            
            sum[x] = add_mod( sum[x], cur );
        }
        return ans;
    }
};
