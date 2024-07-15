//m1

//[A] concat + palindrome shrink dp, but ensure...


//[B] the hard part is to ensure subs1 & subs2 are non-empty.

//1. if two outer endpoints come from 1 & 2, then the above is ensured.

//2. so don't impose any constraints on the typical palindrome dp on the concatenated word.

//3. just use an extra for loop to check [B].1


//O(mn + m^2 + n^2) = 1e6

class Solution {
public:
    string word;
    const int notyet = (-1);
    vector<vector<int>> memo;

    //typical palindrom shrink dp
    int shrink_palin(const string& word, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;

        if(memo[i][j] != notyet) return memo[i][j];

        if(word[i] == word[j]){
            //choose
            return memo[i][j] = 2 + shrink_palin(word, i+1, j-1);
        }else{
            //skip
            return memo[i][j] = max(
                shrink_palin(word, i+1, j),
                shrink_palin(word, i, j-1)
            );
        }
    }

    int longestPalindrome(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        this->word = word1 + word2;

        int mn = word.size();
        //0-indexed instead of 1-indexed with [m+1][n+1] memo size.
        //for bottom up dp, use macro to handle the index (-1)
        memo.resize(mn, vector<int>(mn, notyet));

        int ans = 0;
        //ensures subs1 & subs2 are non-empty
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)if(word1[i] == word2[j]){
                ans = max(
                    ans,
                    shrink_palin(word, i, m + j)
                );
            }
        }
        return ans;
    }
};
