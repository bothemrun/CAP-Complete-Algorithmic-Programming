//m0

//[A] simplified problem / fix some

//1. only 2 kinds of chars / fix the variance to consider only 2 kinds of chars

//2. extra O(26^2) = 6e2 --> so can we have O(n) sol for the simplified?


//[B] chars a/b: +1/-1, others:0 --> maximum subarray sum


//[C] but must include 2 kinds of chars:

//1. just ensure b is included, not a, 'cuz that negative sum without a included will <= dp(b, a)

//2. dp[i] = vanilla max subarray sum of (vanilla, b included)

//O(26^2 * n) = 6e6

#define tii tuple<int,int>
#define inf_add(x, y) ( (x==INT_MIN || y==INT_MIN)? INT_MIN:(x+y) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    const tii notyet = tii(INT_MAX, INT_MAX);
    const int excluded = INT_MIN;

    tii max_suba_included_ending(const string& s, const char a, const char b, vector<tii>& memo, int i){
        if(i<0) return tii(0, excluded);

        if(memo[i] != notyet) return memo[i];

        int cur = 0;
        if(s[i] == a) cur = 1;
        else if(s[i] == b) cur = (-1);

        auto [vanilla, included] = max_suba_included_ending(s, a, b, memo, i-1);

        //choose or skip the cut
        return memo[i] = {
            max(vanilla + cur, cur),

            (
                (s[i] == b)?
                max(vanilla + cur, cur):
                inf_add(
                    included,
                    cur
                )
            )
        };
    }

    int fixed2_max_suba_included(const string& s, const char a, const char b){
        vector<tii> memo(n, notyet);

        int ans = 0;
        for(int end=0;end<n;end++){
            auto [_, included] = max_suba_included_ending(s, a, b, memo, end);

            ans = max(ans, included);
        }
        return ans;
    }

    int largestVariance(string s) {
        this->n = s.size();

        int ans = 0;
        for(char a='a';a<='z';a++)
            for(char b='a';b<='z';b++)if(a != b){
                ans = max(
                    ans,
                    fixed2_max_suba_included(s, a, b)
                );
            }
        return ans;
    }
};
