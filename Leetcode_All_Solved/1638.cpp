//O(n^2) dp recursion with memo

#define notyet (-1)

class Solution {
public:
    vector<vector<vector<int>>> memo;
    int enum_end(const string& s, const string& t, const int& i, const int& j, bool differ){
        if(i<0 || j<0) return 0;

        if(memo[i][j][differ] != notyet)
            return memo[i][j][differ];
        
        if(differ == false){
            if(s[i] != t[j]) return memo[i][j][false] = 0;

            return memo[i][j][false] = 1 + enum_end(s, t, i-1, j-1, false);
        }

        if(s[i] != t[j])
            return memo[i][j][true] = 1 + enum_end(s, t, i-1, j-1, false);
        

        //NOTE: crucial, need 1 differ
        int need_differ = enum_end(s, t, i-1, j-1, true);
        return memo[i][j][true] = (need_differ==0)? 0:need_differ;
    }

    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        memo.resize(m, vector<vector<int>>(n, vector<int>(2, notyet)) );
        
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans += enum_end(s, t, i, j, 1);
        return ans;
    }
};
