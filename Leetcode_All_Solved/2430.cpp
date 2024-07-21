//m0

//[A] dp1(i) for the suffix [i, n-1]
//[B] enumerate j, DP Basic II, check if [i, j-1], [j, j+(len-1)] are equal. (len := (j-1) - (i-1) )


//[C] dp2(i, j+(len-1)) shrink ??

//1. if s[i]==s[j+(len-1)], then i++???
//2. no. we're comparing 2 possible substrings forwards (not forwards + backwards like palindromes)


//[D] dp2(i, j) --> both forwards, so ok.

//O(dp1 + dp2) = O(n^2) + O(n^2)

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<int> memo;
    vector<vector<int>> memo2;

    int lc_suba(const string& s, int i, int j){
        if(!(j<n)) return 0;

        assert(i<j);
        if(memo2[i][j] != notyet) return memo2[i][j];

        return memo2[i][j] = (s[i]==s[j])? (1 + lc_suba(s, i+1, j+1)):0;
    }

    int partition(const string& s, int i){
        assert(i<n);

        if(memo[i] != notyet) return memo[i];

        int ret = 1;//delete the entire substring
        for(int j=i+1;j<n;j++){
            int len = (j-1) - (i-1);
            if(!(j + (len-1)<n)) break;

            if(lc_suba(s, i, j) < len) continue;

            ret = max(
                ret,
                1 + partition(s, j)
            );
        }
        return memo[i] = ret;
    }

    int deleteString(string s) {
        n = s.size();
        memo.resize(n, notyet);
        memo2.resize(n, vector<int>(n, notyet));

        return partition(s, 0);
    }
};
