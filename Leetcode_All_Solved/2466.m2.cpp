//m2
//bottom up dp, enum prefix from m1 instead of suffix from m0
#define mod ((int)1e9 + 7)
#define Memo(i) ( (i<0)? (i==(-1)):memo[i] )
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int low_i = low-1, high_i = high-1;
        vector<int> memo(high);
        for(int done_i=0;done_i<=high_i;done_i++){
            memo[done_i] = ( Memo(done_i - one) + Memo(done_i - zero) )%mod;
        }
        
        int ans = 0;
        for(int done_i=low_i;done_i<=high_i;done_i++)
            ans = (ans + memo[done_i] )%mod;
        return ans;
    }
};
