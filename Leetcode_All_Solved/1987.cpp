//m0

//1. see 940 Distinct Subsequences II hard --> more generalized
//2. all starts with "1"
//3. separately handle a single "0"

//O(n)
//still have O(1) space method, which is derived from this.

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const long long mod = (long long)1e9 + 7;
    const long long notyet = (-1);
    vector<long long> memo;

    vector<int> last;
    const int no_last = (-2);

    long long choose_or_not(const string& s, int i){
        if(i==(-1)) return 0;

        if(memo[i] != notyet) return memo[i];

        long long ret = 2LL * choose_or_not(s, i-1);
        if(last[i] != no_last) ret -= choose_or_not(s, last[i] - 1);
        else ret += s[i] == '1'; //single "1", start.

        return memo[i] = (ret%mod + mod)%mod;
    }

    int numberOfUniqueGoodSubsequences(string binary) {
        int n = binary.size();
        bool has_0 = false;

        last.resize(n);
        vector<int> char2last(2, no_last);
        for(int i=0;i<n;i++){
            last[i] = char2last[ binary[i]-'0' ];

            //update
            char2last[ binary[i]-'0' ] = i;

            has_0 |= binary[i] == '0';
        }

        memo.resize(n, notyet);
        return ( choose_or_not(binary, n-1) + has_0 )%mod;
    }
};
