//m1
//dp two sequences
//O(n^2)

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<int>> memo;

    int ending2seq(const string& s, int i, int j){
        //assert(i != j);
        if(i<0 || j<0) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        if(s[i] != s[j]) return memo[i][j] = 0;
        else return memo[i][j] = 1 + ending2seq(s, i-1, j-1);
    }

    int longestRepeatingSubstring(string s) {
        this->n = s.size();
        memo.resize(n, vector<int>(n, notyet));
        
        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans = max(
                    ans,
                    ending2seq(s, i, j)
                );
        return ans;
    }
};
