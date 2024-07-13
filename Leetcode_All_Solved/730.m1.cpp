//m1

//[A] distinct decision tree:

//1. must choose: s[i]==s[j], use subtraction for duplicates

/*
left := next[i+1][a],
right := prev[j-1][a].

dp(i, j) = {
    {dp(i+1, j-1)},

    a + {dp(i+1, j-1)} + a, (2)
    //outer 2 wrapping

    //now deduplicate:

    if(left < right, left & right also forms a 2 wrapping):
        {dp(left+1, right-1)}
        ////--> duplicate with the above 2 wrapping in (2)
    
    if(left == right):
        {single a not counted yet.}
        //--> no duplicate with the above 2 wrapping in (2)

    if(left > right):
        {outer double a not counted yet.}
        //--> no duplicate with the above 2 wrapping in (2)
}
*/

//2. can't choose. ask the alternative for help with subtraction.

#define mod ((int)1e9 + 7)

class Solution {
public:
    unordered_map<char,int> idx = {
        {'a',0},
        {'b',1},
        {'c',2},
        {'d',3}
    };
    vector<vector<int>> next, prev;
    int n;

    const int notyet = (-1);
    vector<vector<int>> memo;

    int must_choose_alternative_help(const string& s, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;

        if(memo[i][j] != notyet) return memo[i][j];

        int ret;

        if(s[i] == s[j]){
            //wraps 2 outer s[i]
            ret = (
                2 *
                must_choose_alternative_help(s, i+1, j-1)
            )%mod;

            int a = idx[ s[i] ];
            int left = (i+1<n)? next[i+1][a]:n;
            int right = (j-1>=0)? prev[j-1][a]:(-1);

            if(left < right){
                ret = (
                    (
                        ret -
                        must_choose_alternative_help(s, left+1, right-1)
                    )%mod
                    + mod
                )%mod;
            }else if(left == right){
                ret = (ret+1)%mod;
            }else{
                ret = (ret+2)%mod;
            }
        }else{
            //although must choose, we can ask the alternative for help.
            ret =(
                    must_choose_alternative_help(s, i+1, j) +
                    must_choose_alternative_help(s, i, j-1)
            )%mod;

            ret = (
                (
                    ret -
                    must_choose_alternative_help(s, i+1, j-1)
                )%mod
                + mod
            )%mod;
        }

        return memo[i][j] = ret;
    }

    int countPalindromicSubsequences(string s) {
        this->n = s.size();

        next.resize(n, vector<int>(idx.size()));
        for(int a=0;a<(int)idx.size();a++){
            int a_i = 0;

            for(int i=0;i<n;i++){
                a_i = max(a_i, i);

                while(a_i<n && idx[ s[a_i] ] != a){
                    a_i++;
                }

                next[i][a] = a_i;//n means null
            }
        }

        prev.resize(n, vector<int>(idx.size()));
        for(int a=0;a<(int)idx.size();a++){
            int a_i = n-1;

            for(int i=n-1;i>=0;i--){
                a_i = min(a_i, i);

                while(a_i>=0 && idx[ s[a_i] ] != a){
                    a_i--;
                }

                prev[i][a] = a_i;//(-1) means null
            }
        }
        
        memo.resize(n, vector<int>(n, notyet));
        return must_choose_alternative_help(s, 0, n-1);
    }
};
