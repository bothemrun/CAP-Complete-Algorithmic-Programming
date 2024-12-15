//m1
//wisdompeak Dual Sequence on 1
//O(n^2) time, max O(n^3) space & time theoretically (including calculating the hash values).
//no rolling hash.

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<int>> memo;
    int lcs_dual_sequence_on1(const string& text, int i, int j){
        if(!(j<n)) return 0;
        assert(i<j);

        if(memo[i][j] != notyet) return memo[i][j];

        return memo[i][j] = (text[i]==text[j])? ( 1 + lcs_dual_sequence_on1(text, i+1, j+1) ):0;
    }

    int distinctEchoSubstrings(string text) {
        this->n = text.size();
        memo.resize(n, vector<int>(n, notyet));

        unordered_set<string> uset;
        int ans = 0;
        for(int i=0;i<n;i++){
            //part1 [i, j-1]
            //part2 [j, ...]
            for(int j=i+1;j<n;j++){
                //important edge case for 3388. Count Beautiful Splits in an Array medium
                int end2 = j + (j-1)-i;
                if(lcs_dual_sequence_on1(text, i, j) >= (j-1) - (i-1) && end2 < n){
                    uset.insert( text.substr(i, (j-1) - (i-1)) );
                }
            }
        }
        return (int)uset.size();
    }
};
