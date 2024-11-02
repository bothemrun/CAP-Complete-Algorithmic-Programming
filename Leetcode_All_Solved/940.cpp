//m0

//[Thinking Process]

//[A] dp(i) := ending at i, answer = sum all dp[i].
//1. assume i's last index with s[index] == s[i] is j.
//2. but for duplicates like [0, j-1] + s[j] & [0, j-1] + s[i],
//3. we have complex partition like dp(i) = results from dp(j) to dp(i-1)...

//[B] dp(i) := prefix at i.
//1. case 1: not choose s[i] --> dp(i) += dp(i-1)
//2. case 2: choose s[i] --> dp(i) += dp(i-1)
//3. face duplicates in A.3 --> dp(i) -= dp(j-1)

//[C] edge
//1. preprocessing: last[ s[i] ] --> j
//2. special definition: dp(-1) = 1, but non-empty?? so no!!
//3. O(n)

//[D] further: dp(c) or dp(i, c) := ending at char c
//1. derived from this method.

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
        //edge: j == last[i] == 0, then also -= 1 for a single char
        if(last[i] != no_last) ret -= choose_or_not(s, last[i] - 1);
        else ret += 1;//single char
        return memo[i] = (ret%mod + mod)%mod;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        last.resize(n, no_last);
        vector<int> char2last(256, no_last);
        for(int i=0;i<n;i++){
            last[i] = char2last[ s[i] ];

            //update
            char2last[ s[i] ] = i;
        }

        memo.resize(n, notyet);
        return choose_or_not(s, n-1);
    }
};
