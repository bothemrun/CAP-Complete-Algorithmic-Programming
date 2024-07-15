//m0

//[A] wisdompeak shrink DP, interval II


//[B] for backtracking for the result:

//1. check dp(i, n-1) == ans length?

//O(mn) = 2e6

#define inf_add(a,b) ( (a==INT_MAX || b==INT_MAX)? INT_MAX:(a+b) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int notyet = (-1);
    const int impossible = INT_MAX;
    vector<vector<int>> memo;

    int lcs_skippable_useall(const string& s1, const string& s2, int i, int j){
        if(j<0) return 0;//used all s2
        if(i<0) return impossible;//s2 still not depleted, but run out of s1

        if(memo[i][j] != notyet) return memo[i][j];

        int ret = impossible;
        if(s1[i] != s2[j]){
            //skip s1[i] (but still counted in the length of s1 substring)
            ret = inf_add(
                1,
                lcs_skippable_useall(s1, s2, i-1, j)
                );
        }else{
            //even if matched, can still skip s1[i] or not
            //but here since we enforce the end with the for loop, we just choose it right away
            ret = min(
                ret,
                inf_add(
                    1,
                    lcs_skippable_useall(s1, s2, i-1, j-1)
                )
            );
        }

        return memo[i][j] = ret;
    }

    string minWindow(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        //m, not m+1 for memo size. for bottom up dp, use macro for the index (-1).
        memo.resize(m, vector<int>(n, notyet));


        int ans_len = impossible;
        for(int end=n-1;end<m;end++){
            ans_len = min(
                ans_len,
                lcs_skippable_useall(s1, s2, end, n-1)
            );
        }


        if(ans_len == impossible){
            return "";
        }

        for(int end=0;end<m;end++)if( lcs_skippable_useall(s1, s2, end, n-1) == ans_len ){
            assert(end - (ans_len-1) >= 0);
            return s1.substr(end - (ans_len-1), ans_len);
        }
        assert(false);
        return "";
    }
};
