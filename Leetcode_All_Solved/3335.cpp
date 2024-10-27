static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int mod = (int)1e9 + 7;
    const int notyet = (-1);
    vector<int> memo;
    int z_trans(int t){
        assert(t >= 0);
        if(t == 0) return 1;
        if(t <= 25) return 2;
        if(memo[t] != notyet) return memo[t];
        //z, 1 ab, 25 yz, 26 z ab, 27 ab bc
        return memo[t] = (
            z_trans(t - 26) + z_trans(t - 25)
        )%mod;
    }
    int lengthAfterTransformations(string s, int t) {
        memo.resize(t+3, notyet);
        int ans = 0;
        for(char c: s){
            if( t <= (int)('z' - c) ){
                ans = (ans + 1)%mod;
                continue;
            }

            ans = (
                ans + z_trans( t - (int)( 'z' - c ) )
            )%mod;
        }
        return ans;
    }
};
