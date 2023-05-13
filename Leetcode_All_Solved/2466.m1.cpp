//m1
//recursion with memo, enum prefix instead of suffix in m0
#define mod ((int)1e9 + 7)
#define notyet (-1)
class Solution {
public:
    int low_i, high_i, zero, one;
    vector<int> memo;
    int enum_prefix(const int& done_i){
        if(done_i<0) return done_i == (-1);

        if(memo[done_i] != notyet) return memo[done_i];

        return memo[done_i] = (
            enum_prefix(done_i - zero) +
            enum_prefix(done_i - one)
        )%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low_i = low-1;
        this->high_i = high-1;
        this->zero = zero;
        this->one = one;
        memo.resize(high, notyet);

        int ans = 0;
        for(int done_i=low_i;done_i<=high_i;done_i++)
            ans = (ans + enum_prefix(done_i) )%mod;
        return ans;
    }
};
