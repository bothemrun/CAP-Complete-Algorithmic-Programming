//m2
//O(n^2)

class Solution {
public:
    const short notyet = (-1);
    vector<vector<short>> memo;

    bool shrink_is_palin(const string& s, int i, int j){
        if(!(i<=j)) return true;

        if(memo[i][j] != notyet) return memo[i][j];

        if(s[i] != s[j]) return memo[i][j] = false;
        return memo[i][j] = shrink_is_palin(s, i+1, j-1);
    }

    int countSubstrings(string s) {
        int n = s.size();
        memo.resize(n, vector<short>(n, notyet));

        int ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                ans += shrink_is_palin(s, i, j);
        return ans;
    }
};
