//m0

//[A] reverse word2 --> longest common subsequence + palindrome in suffix word1 / word2

//[B] the hard part is to ensure subs1 & subs2 are non-empty.

//O(mn + m^2 + n^2) = 1e6

class Solution {
public:
    int m, n;
    const int notyet = (-1);
    vector<vector<int>> memo_lcs;
    vector< vector<vector<int>> > memo_palin;

    int lcs(const string& word1, const string& word2, int i, int j){
        if(i<0 || j<0) return 0;

        if(memo_lcs[i][j] != notyet) return memo_lcs[i][j];

        if(word1[i] == word2[j]){
            //choose
            return memo_lcs[i][j] = 2 + lcs(word1, word2, i-1, j-1);
        }else{
            //skip
            return memo_lcs[i][j] = max(
                lcs(word1, word2, i-1, j),
                lcs(word1, word2, i, j-1)
            );
        }
    }

    int shrink_palin(const int& idx, const string& word, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;

        if(memo_palin[idx][i][j] != notyet) return memo_palin[idx][i][j];

        if(word[i] == word[j]){
            //choose
            return memo_palin[idx][i][j] = 2 + shrink_palin(idx, word, i+1, j-1);
        }else{
            //skip
            return memo_palin[idx][i][j] = max(
                shrink_palin(idx, word, i+1, j),
                shrink_palin(idx, word, i, j-1)
            );
        }
    }

    int longestPalindrome(string word1, string word2) {
        this->m = word1.size();
        this->n = word2.size();

        //0-indexed instead of 1-indexed with [m+1][n+1] memo size.
        //for bottom up dp, use macro to handle the index (-1)
        memo_lcs.resize(m, vector<int>(n, notyet));
        memo_palin.resize(2);
        memo_palin[0].resize(m, vector<int>(m, notyet));
        memo_palin[1].resize(n, vector<int>(n, notyet));

        reverse(word2.begin(), word2.end());

        int ans = 0;
        for(int i=0;i<m;i++){
            //ensure subs1 & subs2 are non-empty
            int common = lcs(word1, word2, i, n-1);
            if(common==0) continue;

            ans = max(
                ans,
                common +
                shrink_palin(0, word1, i+1, m-1)
            );
        }
        for(int j=0;j<n;j++){
            int common = lcs(word1, word2, m-1, j);
            if(common==0) continue;

            ans = max(
                ans,
                common +
                shrink_palin(1, word2, j+1, n-1)
            );
        }
        return ans;
    }
};
